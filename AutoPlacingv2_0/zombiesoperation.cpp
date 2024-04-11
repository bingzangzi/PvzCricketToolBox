#include "zombiesoperation.h"
vector<bool> global_forbid_zombie;
extern HANDLE pvzHand;
extern HACK<uint8_t, 1> block_main_loop;
void KillAllZombies()
{
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 开始清空僵尸\n").arg(currentTime);
    }
    WriteMemory(block_main_loop.hack_value,{block_main_loop.mem_addr});
    auto zombiemax = ReadMemory<uint32_t>({lawn, board, zombie_count_max});
    auto zombieoffset = ReadMemory<uint32_t>({lawn, board, zombie_offset});
    for (size_t i = 0; i < zombie_count_max; i++)
    {
        if (!ReadMemory<bool>({zombieoffset +zombie_dead + i * zombie_struct_size}))     // 没有消失
            WriteMemory<int>(3, {zombieoffset + zombie_status + i * zombie_struct_size}); // 3 秒杀
    }
    zombiemax = ReadMemory<uint32_t>({lawn, board, zombie_count_max});
    for (size_t i = 0; i < zombie_count_max; i++)
    {
        if (!ReadMemory<bool>({zombieoffset +zombie_dead + i * zombie_struct_size}))     // 没有消失
            WriteMemory<int>(3, {zombieoffset + zombie_status + i * zombie_struct_size}); // 3 秒杀
    }
    WriteMemory(block_main_loop.reset_value,{block_main_loop.mem_addr});
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 结束清空僵尸\n").arg(currentTime);
    }
}

void PutZombie(int type,vector<int>row,vector<int>col)
{
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 开始放置僵尸\n").arg(currentTime);
    }
    CodeStruct* newZombie = Init();
    for(int i=0;i<row.size();i++){
        for(int j=0;j<col.size();j++){
            if (type == 25) // 僵王
            {
                MovRegDwordptr(newZombie,Reg::EAX, lawn);
                MovRegDwordptrOff(newZombie,Reg::EAX,board);
                PushDword(newZombie,0);
                PushDword(newZombie,25);
                Call(newZombie,call_put_zombie_in_row);
                continue;
            }
            PushDword(newZombie, col[j]-1);
            PushDword(newZombie, type);
            MovReg(newZombie, Reg::EAX, row[i]-1);
            MovRegDwordptr(newZombie, Reg::ECX, lawn);
            MovRegDwordptrOff(newZombie, Reg::ECX, board);
            MovRegDwordptrOff(newZombie, Reg::ECX, challenge);
            Call(newZombie, call_place_zombie);
        }
    }
    Ret(newZombie);
    if(CheckBoardOn())CodeInject(pvzHand,newZombie);
    else return;
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 结束放置僵尸\n").arg(currentTime);
    }
}

void PutRandZombie_randmode(bool isforbid,int row,float x,uint32_t addr)
{
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 开始放置随机僵尸\n").arg(currentTime);
    }
    uint32_t nextposiont=ReadMemory<uint32_t>({lawn,board,zombie_next_offset});
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, global_forbid_zombie.size()-1);
    int temp=dis(gen);
    if(isforbid)while(global_forbid_zombie[temp])temp=dis(gen);
    if (temp == 25) // 僵王
    {
        CodeStruct* newZombie = Init();
        MovRegDwordptr(newZombie,Reg::EAX, lawn);
        MovRegDwordptrOff(newZombie,Reg::EAX,board);
        PushDword(newZombie,0);
        PushDword(newZombie,25);
        Call(newZombie,call_put_zombie_in_row);
        Ret(newZombie);
        if(CheckBoardOn())CodeInject(pvzHand,newZombie);
        return;
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 结束随机僵尸\n").arg(currentTime);
        }
    }
    CodeStruct* newZombie = Init();
    PushDword(newZombie, 10);
    PushDword(newZombie, temp);
    MovReg(newZombie, Reg::EAX, row);
    MovRegDwordptr(newZombie, Reg::ECX, lawn);
    MovRegDwordptrOff(newZombie, Reg::ECX, board);
    MovRegDwordptrOff(newZombie, Reg::ECX, challenge);
    Call(newZombie, call_place_zombie);
    Ret(newZombie);
    if(CheckBoardOn())CodeInject(pvzHand,newZombie);
    else return;
    WriteMemory<float>(x,{addr+nextposiont*zombie_struct_size+zombie_xcorordinate});
    uniform_int_distribution<int> dis2(1, 5);
    temp=dis2(gen);
    if(temp==1) WriteMemory<uint32_t>(9999999,{addr+nextposiont*zombie_struct_size+zombie_shining_time});
    uint32_t blood=ReadMemory<uint32_t>({addr+nextposiont*zombie_struct_size+zombie_body_blood});
    WriteMemory<uint32_t>(blood/temp,{addr+nextposiont*zombie_struct_size+zombie_body_blood});
    uint32_t blood2=ReadMemory<uint32_t>({addr+nextposiont*zombie_struct_size+zombie_armor1_body});
    if(blood2)WriteMemory<uint32_t>(blood2/temp,{addr+nextposiont*zombie_struct_size+zombie_armor1_body});
    uint32_t blood3=ReadMemory<uint32_t>({addr+nextposiont*zombie_struct_size+zombie_armor2_body});
    if(blood3)WriteMemory<uint32_t>(blood3/temp,{addr+nextposiont*zombie_struct_size+zombie_armor2_body});
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 结束随机僵尸\n").arg(currentTime);
    }
}


void SingleZombiePut(ZombieInfoStruct zom,uint32_t addr)
{
    if(zom.row>GetRowCount()) return;
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 开始放置僵尸\n").arg(currentTime);
    }
    uint32_t nextposiont=ReadMemory<uint32_t>({lawn,board,zombie_next_offset});
    CodeStruct* newZombie = Init();
    if (zom.type == 25) // 僵王
    {
        MovRegDwordptr(newZombie,Reg::EAX, lawn);
        MovRegDwordptrOff(newZombie,Reg::EAX,board);
        PushDword(newZombie,0);
        PushDword(newZombie,25);
        Call(newZombie,call_put_zombie_in_row);
    }
    else{
        PushDword(newZombie, zom.col-1);
        PushDword(newZombie, zom.type);
        MovReg(newZombie, Reg::EAX, zom.row-1);
        MovRegDwordptr(newZombie, Reg::ECX, lawn);
        MovRegDwordptrOff(newZombie, Reg::ECX, board);
        MovRegDwordptrOff(newZombie, Reg::ECX, challenge);
        Call(newZombie, call_place_zombie);
    }
    Ret(newZombie);
    if(CheckBoardOn())CodeInject(pvzHand,newZombie);
    else return;
    WriteMemory<float>(zom.x,{addr+nextposiont*zombie_struct_size+zombie_xcorordinate});
    WriteMemory<float>(zom.y,{addr+nextposiont*zombie_struct_size+zombie_ycorordinate});
    if(zom.shingingtime)WriteMemory<uint32_t>(zom.shingingtime,{addr+nextposiont*zombie_struct_size+zombie_shining_time});
    if(zom.bodyblood)WriteMemory<uint32_t>(zom.bodyblood,{addr+nextposiont*zombie_struct_size+zombie_body_blood});
    if(zom.armorblood1)WriteMemory<uint32_t>(zom.armorblood1,{addr+nextposiont*zombie_struct_size+zombie_armor1_body});
    if(zom.armorblood2)WriteMemory<uint32_t>(zom.armorblood2,{addr+nextposiont*zombie_struct_size+zombie_armor2_body});
    if(zom.buttertime)WriteMemory<uint32_t>(zom.buttertime,{addr+nextposiont*zombie_struct_size+zombie_butter_time});
    if(zom.slowingtime)WriteMemory<uint32_t>(zom.slowingtime,{addr+nextposiont*zombie_struct_size+zombie_slow_down_time});
    if(zom.frozentime)WriteMemory<uint32_t>(zom.frozentime,{addr+nextposiont*zombie_struct_size+zombie_freeze_time});
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 结束放置僵尸\n").arg(currentTime);
    }
}
