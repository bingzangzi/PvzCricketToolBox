#include "zombies.h"
void PlaceZombie(int row, int col, int type)
{
    CodeStruct* newZombie = Init();
    PushDword(newZombie, col);
    PushDword(newZombie, type);
    MovReg(newZombie, Reg::EAX, row);
    MovRegDwordptr(newZombie, Reg::ECX, lawn);
    MovRegDwordptrOff(newZombie, Reg::ECX, board);
    MovRegDwordptrOff(newZombie, Reg::ECX, challenge);
    Call(newZombie, call_place_zombie);
    Ret(newZombie);
    CodeInject(newZombie);
}
void ZombieColumPlace(int col,int type)
{
    int maxrow=GetRowCount();
    for (int i = 0; i < maxrow; i++) {
        PlaceZombie(i, col, type);
    }

}

void KillAllZombies()
{
    auto zombiemax = ReadMemory<uint32_t>({lawn, board, zombie_count_max});
    auto zombieoffset = ReadMemory<uint32_t>({lawn, board, zombie_offset});
    for (size_t i = 0; i < zombie_count_max; i++)
    {
        if (!ReadMemory<bool>({zombieoffset +zombie_dead + i * zombie_struct_size}))     // 没有消失
            WriteMemory<int>(3, {zombieoffset + zombie_status + i * zombie_struct_size}); // 3 秒杀
    }
}

