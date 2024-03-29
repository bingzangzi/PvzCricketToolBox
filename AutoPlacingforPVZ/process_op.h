#ifndef PROCESS_OP_H
#define PROCESS_OP_H
#pragma once
#include <string>
#include <array>
#include <windows.h>
#include <tlhelp32.h>
#include <vector>
#include <initializer_list>
using namespace std;

#define call_place_plant  0x0040d120
#define call_place_zombie  0x0042a0f0
#define challenge  0x160
#define lawn 0x6a9ec0
#define board 0x768
#define plant_offset 0xac
#define plant_count_max 0xb0
#define plant_curren_count 0xbc
#define plant_dead 0x141
#define plant_squished 0x142
#define call_delete_plant 0x004679b0
#define plant_single_size 0x14c
#define plant_row 0x1c
#define plant_col 0x28
#define plant_type 0x24
#define plant_blood 0x40
#define plant_next_plant_position 0xb8
#define plant_last_number 0xc0
#define plant_attack_interval 0x5c
#define plant_shine_time 0xb8
#define plant_asleep 0x143

#define game_mode 0x7f8
#define game_ui 0x7fc
#define game_scene 0x554c
#define game_pause 0x164

#define lawn_mower 0x100
#define lawn_mower_row 0x14
#define lawn_mower_next 0x48
#define lawn_mower_isfalse 0x30
#define lawn_mower_limit 0x108
#define lawn_mower_count_max 0x104
#define lawn_mower_current_count 0x110
#define lawn_mower_state 0x2c
#define call_start_lawn_mower 0x00458da0
#define call_delete_lawn_mower 0x00458d10
#define call_restore_lawn_mower  0x0040bc70
#define call_set_plant_sleeping 0x0045e860

#define zombie_dead 0xec
#define zombie_count_max 0x94
#define zombie_struct_size 0x15c
#define zombie_offset 0x90
#define zombie_status 0x28
#define zombie_current_count 0xa0
#define zombie_next_offset 0x9c
#define zombie_body_blood 0xc8
#define zombie_armor1_isexist 0xc4
#define zombie_armor1_body 0xd0
#define zombie_armor2_isexist 0xd8
#define zombie_armor2_body 0xdc
#define zombie_ishypno 0xb8
#define zombie_type 0x24
#define zombie_slow_down_time 0xac
#define zombie_butter_time 0xb0
#define zombie_freeze_time 0xb4
#define zombie_shining_time 0x54
#define zombie_row 0x1c
#define zombie_xcorordinate 0x8
#define zombie_ycorordinate 0xc

#define sunshine_value 0x5560
#define free_plant 0x814
#define window_and_mouse 0x320
#define window_focused 0x84
#define cursor_off 0x138
#define cursor_grab 0x30
#define slot_offset 0x144
#define slot_hide 0x18
#define slot_count 0x24
#define slot_seed_cd_total 0x50
#define slot_seed_cd_past 0x4c
#define user_data 0x82c
#define playthrough 0x2c
#define mini_games 0x30
#define tree_height 0xf4
#define twiddydinky 0x1c0


template <typename T, size_t size>
struct HACK
{
    uintptr_t mem_addr;
    std::array<T, size> hack_value;
    std::array<T, size> reset_value;
};


struct CodeStruct//代码结构体
{
    unsigned char* code;
    unsigned int length;
    vector<unsigned int> callAddr;
};


enum class Reg : unsigned int//寄存器对应编号
{
    EAX = 0,
    EBX = 3,
    ECX = 1,
    EDX = 2,
    ESI = 6,
    EDI = 7,
    EBP = 5,
    ESP = 4,
};

extern wstring PvzName;
inline DWORD GetProcessId(wstring& processName) {
    PROCESSENTRY32 processEntry; // 定义进程快照结构体
    processEntry.dwSize = sizeof(PROCESSENTRY32); // 设置结构体大小

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL); // 创建进程快照
    if (Process32First(snapshot, &processEntry)) { // 获取第一个进程快照
        do {
            if (processName.compare(processEntry.szExeFile) == 0) { // 比较进程名是否匹配
                CloseHandle(snapshot); // 关闭进程快照句柄
                return processEntry.th32ProcessID; // 返回进程ID
            }
        } while (Process32Next(snapshot, &processEntry)); // 获取下一个进程快照
    }

    CloseHandle(snapshot); // 关闭进程快照句柄
    return 0; // 未找到匹配的进程，返回0
}

inline HANDLE GetHandle(wstring& pvzname)
{
    DWORD pvzPid = GetProcessId(pvzname);
    return OpenProcess(PROCESS_ALL_ACCESS, false, pvzPid);
}

inline void CodeInject(CodeStruct* target)
{
    //wstring pvzname=L"PlantsVsZombies.exe";
    HANDLE pvzHand = GetHandle(PvzName);
    // 在另一个进程的虚拟地址空间中分配内存
    LPVOID addr = VirtualAllocEx(pvzHand, nullptr, target->length, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    if (addr == nullptr) return;

    //对函数调用指令进行修正，确保在不同内存地址中执行时仍然能够正确地调用到目标函数
    for (size_t i = 0; i < target->callAddr.size(); i++)
    {
        unsigned int pos = target->callAddr[i];
        int& CallAddr = (int&)target->code[pos];
        CallAddr = CallAddr - (reinterpret_cast<uintptr_t>(addr) + pos + 4);
    }

    //写入代码
    SIZE_T write_size = 0;
    BOOL ret = WriteProcessMemory(pvzHand, addr, target->code, target->length, &write_size);
    if (ret == 0 || write_size != target->length)
    {
        VirtualFreeEx(pvzHand, addr, 0, MEM_RELEASE);
        return;
    }

    //创建远程线程，以便执行上面写入的代码
    HANDLE thread = CreateRemoteThread(pvzHand, nullptr, 0, LPTHREAD_START_ROUTINE(addr), nullptr, 0, nullptr);
    if (thread == nullptr)
    {
        VirtualFreeEx(pvzHand, addr, 0, MEM_RELEASE);
        return;
    }
    //待远程线程的执行完成，并在完成后关闭线程句柄以及释放先前分配的内存空间。
    DWORD wait_status = WaitForSingleObject(thread, INFINITE);
    CloseHandle(thread);
    VirtualFreeEx(pvzHand, addr, 0, MEM_RELEASE);

}

inline CodeStruct* Init()
{
    CodeStruct* newCode = new CodeStruct;
    newCode->code = new unsigned char[4096 * 256]; //分配的内存大小
    newCode->length = 0;
    newCode->callAddr.clear();
    return newCode;
}

inline void AddByte(CodeStruct* Code, unsigned char value)
{
    Code->code[Code->length++] = value;
}

inline void AddWord(CodeStruct* Code, unsigned short value)
{
    (unsigned short&)Code->code[Code->length] = value;
    Code->length += 2;
}

inline void AddDword(CodeStruct* Code, unsigned int value)
{
    (unsigned int&)Code->code[Code->length] = value;
    Code->length += 4;
}

inline void AddList(CodeStruct* Code, initializer_list<unsigned char> value)
{
    for (auto iter = value.begin(); iter != value.end(); iter++)
        AddByte(Code, *iter);
}
template <typename... Args>
inline void AddList(CodeStruct* Code, Args...);

inline void PushByte(CodeStruct* Code, unsigned char value)
{
    AddByte(Code,0x6a);
    AddByte(Code, value);
}

inline void PushDword(CodeStruct* Code, unsigned int value)
{
    AddByte(Code, 0x68);
    AddDword(Code, value);
}

inline void MovReg(CodeStruct* Code, Reg reg, unsigned int value)
{
    AddByte(Code, 0xb8 + static_cast<unsigned int>(reg));
    AddDword(Code, value);
}

inline void MovRegDwordptr(CodeStruct* Code, Reg reg, unsigned int value)
{
    AddByte(Code, 0x8b);
    AddByte(Code, 0x05 + static_cast<unsigned int>(reg) * 8);
    AddDword(Code, value);
}

inline void MovRegDwordptrOff(CodeStruct* Code, Reg reg, unsigned int value)
{
    AddByte(Code, 0x8b);
    AddByte(Code, 0x80 + static_cast<unsigned int>(reg) * (8 + 1));
    if (reg == Reg::ESP)
        AddByte(Code, 0x24);
    AddDword(Code, value);
}

inline void PushReg(CodeStruct* Code, Reg reg)
{
    AddByte(Code, 0x50 + static_cast<unsigned int>(reg));
}

inline void PopReg(CodeStruct* Code, Reg reg)
{
    AddByte(Code, 0x58 + static_cast<unsigned int>(reg));
}

inline void MovRegtoReg(CodeStruct* Code, Reg reg_to, Reg reg_from)
{
    AddByte(Code, 0x8b);
    AddByte(Code, 0xc0 + static_cast<unsigned int>(reg_to) * 8 + static_cast<unsigned int>(reg_from));
}

inline void Call(CodeStruct* Code, unsigned int addr)
{
    AddByte(Code, 0xe8);
    Code->callAddr.push_back(Code->length);
    AddDword(Code, addr);
}

inline void Ret(CodeStruct* Code)
{
    AddByte(Code, 0xc3);
}

template <typename T>
T ReadMemory(initializer_list<uintptr_t> addr)
{
    extern wstring PvzName;
    HANDLE pvzHand = GetHandle(PvzName);
    T result=T();
    uintptr_t offset=0;
    for (auto it = addr.begin(); it != addr.end(); it++)
    {
        if (it != addr.end() - 1)
        {
            SIZE_T read_size = 0;
            int ret = ReadProcessMemory(pvzHand, (const void *)(offset + *it), &offset, sizeof(offset), &read_size);
            if (ret == 0 || sizeof(offset) != read_size)
                return T();
        }
        else
        {
            SIZE_T read_size = 0;
            int ret = ReadProcessMemory(pvzHand, (const void *)(offset + *it), &result, sizeof(result), &read_size);
            if (ret == 0 || sizeof(result) != read_size)
                return T();
        }
    }
    return result;
}

template <>
inline string ReadMemory<string>(initializer_list<uintptr_t> addr)
{
    extern wstring PvzName;
    string result = string();
    HANDLE pvzHand = GetHandle(PvzName);
    uintptr_t offset = 0;
    for (auto it = addr.begin(); it != addr.end(); it++)
    {
        if (it != addr.end() - 1)
        {
            SIZE_T read_size = 0;
            int ret = ReadProcessMemory(pvzHand, (const void *)(offset + *it), &offset, sizeof(offset), &read_size);
            if (ret == 0 || sizeof(offset) != read_size)
                return string();
        }
        else
        {
            SIZE_T read_size = 0;
            int ret = 0;
            char ch = 0;

        read_letter:
            ret = ReadProcessMemory(pvzHand, (const void *)(offset + *it), &ch, sizeof(ch), &read_size);
            while (read_size == sizeof(ch) && ret != 0 && ch != 0)
            {
                result += ch;
                offset += sizeof(ch);
                goto read_letter;
            }
        }
    }
    return result;
}

template <typename T>
void WriteMemory(T value, initializer_list<uintptr_t> addr)
{
    extern wstring PvzName;
    HANDLE pvzHand = GetHandle(PvzName);
    uintptr_t offset = 0;
    for (auto it = addr.begin(); it != addr.end(); it++)
    {
        if (it != addr.end() - 1)
        {
            SIZE_T read_size = 0;
            int ret = ReadProcessMemory(pvzHand, (const void *)(offset + *it), &offset, sizeof(offset), &read_size);
            if (ret == 0 || sizeof(offset) != read_size)
                return;
        }
        else
        {
            SIZE_T write_size = 0;
            int ret = WriteProcessMemory(pvzHand, (void *)(offset + *it), &value, sizeof(value), &write_size);
            if (ret == 0 || sizeof(value) != write_size)
                return;
        }
    }
}

template <typename T, size_t size>
array<T, size> ReadMemory(initializer_list<uintptr_t> addr)
{
    extern wstring PvzName;
    array<T, size> result = {T()};
    HANDLE pvzHand = GetHandle(PvzName);
    T buff[size] = {0};
    uintptr_t offset = 0;
    for (auto it = addr.begin(); it != addr.end(); it++)
    {
        if (it != addr.end() - 1)
        {
            SIZE_T read_size = 0;
            int ret = ReadProcessMemory(pvzHand, (const void *)(offset + *it), &offset, sizeof(offset), &read_size);
            if (ret == 0 || sizeof(offset) != read_size)
                return array<T, size>{T()};
        }
        else
        {
            SIZE_T read_size = 0;
            int ret = ReadProcessMemory(pvzHand, (const void *)(offset + *it), &buff, sizeof(buff), &read_size);
            if (ret == 0 || sizeof(buff) != read_size)
                return array<T, size>{T()};
        }
    }
    for (size_t i = 0; i < size; i++)
        result[i] = buff[i];
    return result;
}

template <typename T, size_t size>
void WriteMemory(array<T, size> value, initializer_list<uintptr_t> addr)
{
    extern wstring PvzName;
    HANDLE pvzHand = GetHandle(PvzName);
    T buff[size] = {0};
    for (size_t i = 0; i < size; i++)
        buff[i] = value[i];
    uintptr_t offset = 0;
    for (auto it = addr.begin(); it != addr.end(); it++)
    {
        if (it != addr.end() - 1)
        {
            SIZE_T read_size = 0;
            int ret = ReadProcessMemory(pvzHand, (const void *)(offset + *it), &offset, sizeof(offset), &read_size);
            if (ret == 0 || sizeof(offset) != read_size)
                return;
        }
        else
        {
            SIZE_T write_size = 0;
            int ret = WriteProcessMemory(pvzHand, (void *)(offset + *it), &buff, sizeof(buff), &write_size);
            if (ret == 0 || sizeof(buff) != write_size)
                return;
        }
    }
}

#endif // PROCESS_OP_H
