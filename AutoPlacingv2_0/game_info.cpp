#include "game_info.h"
HACK<uint8_t,1> init_lawn_mower {0x0040bd14 + 3, {0x01}, {0x00}};
HACK<uint32_t, 1> lawn_mower_initialize {0x00458000 + 2, {0x006799fc}, {0x00679bf8}};
HACK<uint8_t, 1> placed_anywhere {0x0040fe30, {0x81}, {0x84}};
HACK<uint8_t, 1> placed_anywhere_preview {0x00438e40, {0xeb}, {0x74}};
HACK<uint8_t, 1> placed_anywhere_iz {0x0042a2d9, {0x8d}, {0x84}};
HACK<uint8_t, 1> lock_shovel {0x004123a3, {0x39}, {0x89}};
HACK<uint8_t, 3> plant_immune_eat  {0x0052fcf1, {0x46, 0x40, 0x00}, {0x46, 0x40, 0xfc}};
HACK<uint8_t, 1> plant_immune_radius {0x0041cc2f, {0xeb}, {0x74}};
HACK<uint8_t, 1> plant_immune_jalapeno {0x005276ea, {0xeb}, {0x75}};
HACK<uint8_t, 3> plant_immune_projectile {0x0046cfeb, {0x90, 0x90, 0x90}, {0x29, 0x50, 0x40}};
HACK<uint8_t, 3> plant_immune_lob_motion {0x0046d7a6, {0x90, 0x90, 0x90}, {0x29, 0x4e, 0x40}};
HACK<uint8_t, 1> plant_immune_square {0x0052e93b, {0xeb}, {0x74}};
HACK<uint8_t, 1> plant_immune_row_area {0x0045ee0a, {0x70}, {0x75}};
HACK<uint8_t, 1> plant_immune_spike_rock {0x0045ec66, {0x00}, {0xce}};
HACK<uint8_t, 3> plant_immune_squish {0x00462b80, {0xc2, 0x04, 0x00}, {0x53, 0x55, 0x8b}};
HACK<uint8_t, 3> _plant_immune_eat {0x0052fcf1, {0x66, 0x40, 0x00}, {0x46, 0x40, 0xfc}};
HACK<uint8_t, 3> _plant_immune_projectile {0x0046cfeb, {0x29, 0x40, 0x40}, {0x29, 0x50, 0x40}};
HACK<uint8_t, 3> _plant_immune_lob_motion {0x0046d7a6, {0x29, 0x76, 0x40}, {0x29, 0x4e, 0x40}};
HACK<uint8_t, 1> _plant_immune_row_area {0x0045ee0a, {0xeb}, {0x75}};
HACK<uint32_t, 1> zombie_immune_body_damage {0x0053130f, {0x90909090}, {0x20247c2b}};
HACK<uint8_t, 2> zombie_immune_helm_damage {0x00531044, {0x2b, 0xc0}, {0x2b, 0xc8}};
HACK<uint32_t, 1> zombie_immune_shield_damage {0x00530c9b, {0xd233c033}, {0xc28b027c}};
HACK<uint8_t, 1> zombie_immune_burn_crumble {0x00532ba1, {0x81}, {0x8d}};
HACK<uint8_t, 1> zombie_immune_radius {0x0041d8ff, {0xeb}, {0x7f}};
HACK<uint8_t, 1> zombie_immune_burn_row {0x004664f2, {0xeb}, {0x75}};
HACK<uint8_t, 1> zombie_immune_chomper  {0x0046144a, {0xeb}, {0x74}};
HACK<uint8_t, 1> zombie_immune_mind_controll  {0x0052fa82, {0x00}, {0x01}};
HACK<uint8_t, 2> zombie_immune_blow_away {0x00466601, {0x90, 0x90}, {0x74, 0x05}};
HACK<uint8_t, 1> zombie_immune_splash {0x0046d455, {0xeb}, {0x74}};
HACK<uint8_t, 1> zombie_immune_lawn_mower  {0x00458836, {0xeb}, {0x74}};
HACK<uint8_t, 1> mushrooms_awake {0x0045de8e, {0xeb}, {0x74}};
HACK<uint8_t, 1> stop_spawning {0x004265dc, {0xeb}, {0x74}};
std::vector<HACK<uint8_t, 1>> stop_zombies {{0x0052ab2b, {0x54}, {0x64}}, {0x0052ab34, {0x54}, {0x44}}};
HACK<uint8_t, 1> no_crater {0x0041d79e, {0x70}, {0x75}};
HACK<uint16_t, 1> background_running {0x0054eba8, {0x00eb}, {0x2e74}} ;
HACK<uint8_t, 1> block_main_loop={0x00552014, {0xfe}, {0xdb}};

int GetFrameDuration()
{
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 开始获取帧生成时间\n").arg(currentTime);
    }
    int time_ms = 10;
    if(!CheckGameOn()) return time_ms;
    time_ms = ReadMemory<int>({lawn, frame_duration});
    return time_ms;
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 结束获取帧生成时间\n").arg(currentTime);
    }
}

void CodeInject(HANDLE pvzHand,CodeStruct* target)
{
    WriteMemory(block_main_loop.hack_value,{block_main_loop.mem_addr});
    //Sleep(GetFrameDuration() * 2);
    _CodeInject(pvzHand,target);
    WriteMemory(block_main_loop.reset_value,{block_main_loop.mem_addr});
}

bool IsProcessRunning() {
    DWORD dwWaitResult = WaitForSingleObject(pvzHand, 0);
    return (dwWaitResult == WAIT_TIMEOUT);
}

int GetGameUI()
{
    return ReadMemory<int>({lawn,game_ui});
}

int GetGameMode()
{
    return ReadMemory<int>({lawn,game_mode});
}

int GetScene()
{
    int scene=-1;
    int ui=GetGameUI();
    if(ui==2||ui==3)
        scene=ReadMemory<int>({lawn,board,game_scene});
    return scene;
}

int GetRowCount()
{
    int scene=GetScene();
    return (scene==2||scene==3)?6:5;
}

bool CheckGameOn()
{
    if(IsProcessRunning()) return true;
    extern wstring PVZNAME;
    pvzHand=GetHandle(PVZNAME);
    if(pvzHand)return true;
    else return false;
}

bool CheckBoardOn()
{
    if(!CheckGameOn()) return false;
    auto check=ReadMemory<uint32_t>({lawn,board});
    if(check) return true;
    return false;
}

bool Resumemower()
{
    if (!CheckBoardOn())
        return false;
    Clearmower(0);
    WriteMemory(init_lawn_mower.hack_value,{init_lawn_mower.mem_addr});
    WriteMemory(lawn_mower_initialize.hack_value,{lawn_mower_initialize.mem_addr});
    CodeStruct* resumecode=Init();
    MovRegDwordptr(resumecode,Reg::EAX,lawn);
    MovRegDwordptrOff(resumecode,Reg::EAX,board);
    PushReg(resumecode,Reg::EAX);
    Call(resumecode,call_restore_lawn_mower);
    Ret(resumecode);
    CodeInject(pvzHand,resumecode);
    return true;
}

bool Startmower(int row)
{
    if (!CheckBoardOn())
        return false;
    uint32_t moweroffset=ReadMemory<uint32_t>({lawn,board,lawn_mower});
    auto maxmower=ReadMemory<uint32_t>({lawn,board,lawn_mower_count_max});
    for(int i=0;i<maxmower;i++)
    {
        auto lawn_mower_dead = ReadMemory<bool>({moweroffset + lawn_mower_isfalse + lawn_mower_next * i});

        if(row==0&&!lawn_mower_dead){
            CodeStruct* startcode=Init();
            MovReg(startcode,Reg::ESI,moweroffset+lawn_mower_next*i);
            Call(startcode,call_start_lawn_mower);
            Ret(startcode);
            CodeInject(pvzHand,startcode);
            //WriteMemory<uint32_t>(2,{moweroffset+lawn_mower_state+lawn_mower_next*i});
        }
        else if(!lawn_mower_dead&&row!=0){
            auto mowerrow=ReadMemory<uint32_t>({moweroffset+lawn_mower_row+lawn_mower_next*i});
            if(row-1!=mowerrow) continue;
            CodeStruct* startcode=Init();
            MovReg(startcode,Reg::ESI,moweroffset+lawn_mower_next*i);
            Call(startcode,call_start_lawn_mower);
            Ret(startcode);
            CodeInject(pvzHand,startcode);
            //WriteMemory<uint32_t>(2,{moweroffset+lawn_mower_state+lawn_mower_next*i});
        }
    }
    return true;
}

bool Clearmower(int row)
{
    if (!CheckBoardOn())
        return false;
    uint32_t moweroffset=ReadMemory<uint32_t>({lawn,board,lawn_mower});
    auto maxmower=ReadMemory<uint32_t>({lawn,board,lawn_mower_count_max});
    for(int i=0;i<maxmower;i++)
    {
        auto lawn_mower_dead = ReadMemory<bool>({moweroffset + lawn_mower_isfalse + lawn_mower_next * i});
        //auto mowerrow=ReadMemory<uint32_t>({moweroffset+lawn_mower_row+lawn_mower_next*i});
        if(row==0&&!lawn_mower_dead){
            CodeStruct* clearcode=Init();
            MovReg(clearcode,Reg::EAX,moweroffset+lawn_mower_next*i);
            Call(clearcode,call_delete_lawn_mower);
            Ret(clearcode);
            CodeInject(pvzHand,clearcode);
            //WriteMemory<uint32_t>(3,{moweroffset+lawn_mower_state+lawn_mower_next*i});
        }
        else if(!lawn_mower_dead&&row!=0){
            auto mowerrow=ReadMemory<uint32_t>({moweroffset+lawn_mower_row+lawn_mower_next*i});
            if(row-1!=mowerrow) continue;
            CodeStruct* clearcode=Init();
            MovReg(clearcode,Reg::EAX,moweroffset+lawn_mower_next*i);
            Call(clearcode,call_delete_lawn_mower);
            Ret(clearcode);
            CodeInject(pvzHand,clearcode);
        }
    }
    return true;
}

void SetGamePause()
{
    if (!CheckBoardOn())
        return;
    auto isGamePaused=ReadMemory<bool>({lawn,board,game_pause});
    WriteMemory<bool>(!isGamePaused,{lawn,board,game_pause});
}

void PlantNoLimit(bool on)
{
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 开始设置自由种植\n").arg(currentTime);
    }
    if (!CheckGameOn())
        return;
    if(on) WriteMemory(placed_anywhere.hack_value,{placed_anywhere.mem_addr});
    else WriteMemory(placed_anywhere.reset_value,{placed_anywhere.mem_addr});
    if(on) WriteMemory(placed_anywhere_preview.hack_value,{placed_anywhere_preview.mem_addr});
    else WriteMemory(placed_anywhere_preview.reset_value,{placed_anywhere_preview.mem_addr});
    if(on) WriteMemory(placed_anywhere_iz.hack_value,{placed_anywhere_iz.mem_addr});
    else WriteMemory(placed_anywhere_iz.reset_value,{placed_anywhere_iz.mem_addr});
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 结束设置自由种植\n").arg(currentTime);
    }
}

void LockShovel(bool on)
{
    if (!CheckBoardOn())
        return;
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 开始设置鼠标锁定铲子\n").arg(currentTime);
    }
    if(on) WriteMemory(lock_shovel.hack_value,{lock_shovel.mem_addr});
    else WriteMemory(lock_shovel.reset_value,{lock_shovel.mem_addr});

    auto cursor_offset = ReadMemory<uint32_t>({lawn, board, cursor_off});
    if(on){
        WriteMemory<uint32_t>(6,{cursor_offset+cursor_grab});
    }
    else {
        if(ReadMemory<uint32_t>({cursor_offset+cursor_grab})==6)
            WriteMemory<uint32_t>(0,{cursor_offset+cursor_grab});
    }
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 结束设置鼠标锁定铲子\n").arg(currentTime);
    }
}

void PlantInvincible(bool on)
{

    if (!CheckGameOn())
        return;
    //这一段有问题，会导致游戏崩溃。暂且不用
    // if(on) WriteMemory(plant_immune_eat.hack_value,{plant_immune_eat.mem_addr});
    //else WriteMemory(plant_immune_eat.reset_value,{plant_immune_eat.mem_addr});
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 开始设置植物无敌。\n").arg(currentTime);
    }
    if(on) WriteMemory(plant_immune_radius.hack_value,{plant_immune_radius.mem_addr});
    else WriteMemory(plant_immune_radius.reset_value,{plant_immune_radius.mem_addr});

    if(on) WriteMemory(plant_immune_jalapeno.hack_value,{plant_immune_jalapeno.mem_addr});
    else WriteMemory(plant_immune_jalapeno.reset_value,{plant_immune_jalapeno.mem_addr});

    if(on) WriteMemory(plant_immune_projectile.hack_value,{plant_immune_projectile.mem_addr});
    else WriteMemory(plant_immune_projectile.reset_value,{plant_immune_projectile.mem_addr});

    if(on) WriteMemory(plant_immune_lob_motion.hack_value,{plant_immune_lob_motion.mem_addr});
    else WriteMemory(plant_immune_lob_motion.reset_value,{plant_immune_lob_motion.mem_addr});

    if(on) WriteMemory(plant_immune_square.hack_value,{plant_immune_square.mem_addr});
    else WriteMemory(plant_immune_square.reset_value,{plant_immune_square.mem_addr});

    if(on) WriteMemory(plant_immune_row_area.hack_value,{plant_immune_row_area.mem_addr});
    else WriteMemory(plant_immune_row_area.reset_value,{plant_immune_row_area.mem_addr});

    if(on) WriteMemory(plant_immune_spike_rock.hack_value,{plant_immune_spike_rock.mem_addr});
    else WriteMemory(plant_immune_spike_rock.reset_value,{plant_immune_spike_rock.mem_addr});

    if(on) WriteMemory(plant_immune_squish.hack_value,{plant_immune_squish.mem_addr});
    else WriteMemory(plant_immune_squish.reset_value,{plant_immune_squish.mem_addr});
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 结束设置植物无敌。\n").arg(currentTime);
    }
}

void UnlockAllMode(bool on)
{
    if (CheckGameOn())
    {
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 开始设置解锁所有模式\n").arg(currentTime);
        }
        if (on)
        {
            WriteMemory<uint8_t>(0x70, {0x0044a514});
            WriteMemory(std::array<uint8_t, 3>{0x31, 0xc0, 0xc3}, {0x0042e440});
            WriteMemory<uint8_t>(0x70, {0x0044a5af});
            WriteMemory<uint8_t>(0x70, {0x00454109});
            WriteMemory<uint8_t>(0xeb, {0x00449e7a});
            WriteMemory<uint8_t>(0xeb, {0x00449e9d});
            WriteMemory<uint8_t>(0xeb, {0x00453ad1});
            WriteMemory<uint32_t>(0x5beb01b0, {0x00403a10});
            WriteMemory(std::array<uint8_t, 3>{0xb0, 0x01, 0xc3}, {0x00403b30});
            WriteMemory<uint32_t>(0x00, {0x0069dca0});
            WriteMemory(std::array<uint8_t, 3>{0x30, 0xc0, 0xc3}, {0x0048aad0});
            WriteMemory<uint8_t>(0xeb, {0x0048a54c});
            WriteMemory<uint8_t>(0xeb, {0x0048d32b});
            WriteMemory<uint8_t>(0xeb, {0x0048c491});
        }
        else
        {
            WriteMemory<uint8_t>(0x7e, {0x0044a514});
            WriteMemory(std::array<uint8_t, 3>{0x51, 0x53, 0x55}, {0x0042e440});
            WriteMemory<uint8_t>(0x7e, {0x0044a5af});
            WriteMemory<uint8_t>(0x7e, {0x00454109});
            WriteMemory<uint8_t>(0x7f, {0x00449e7a});
            WriteMemory<uint8_t>(0x7f, {0x00449e9d});
            WriteMemory<uint8_t>(0x7f, {0x00453ad1});
            WriteMemory<uint32_t>(0x6c8b5551, {0x00403a10});
            WriteMemory(std::array<uint8_t, 3>{0x8b, 0x80, 0x6c}, {0x00403b30});
            WriteMemory<uint32_t>(0x28, {0x0069dca0});
            WriteMemory(std::array<uint8_t, 3>{0x53, 0x8b, 0xd9}, {0x0048aad0});
            WriteMemory<uint8_t>(0x7f, {0x0048a54c});
            WriteMemory<uint8_t>(0x7f, {0x0048d32b});
            WriteMemory<uint8_t>(0x7f, {0x0048c491});
        }

        // 刷新主界面
        if (GetGameUI() == 1)
        {
            CodeStruct* newcode=Init();
            PushByte(newcode,1); // 显示 Loading
            MovRegDwordptr(newcode,Reg::ECX, 0x6a9ec0);
            MovRegDwordptrOff(newcode,Reg::ECX, 0x770);
            Call(newcode,0x0044a320);
            Ret(newcode);
            CodeInject(pvzHand,newcode);
        }
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 结束设置解锁所有模式\n").arg(currentTime);
        }
    }
}

void UnlockGoldFlower(bool on)
{
    if (!CheckGameOn())
        return;
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 开始设置解锁金向日葵\n").arg(currentTime);
    }
    uint32_t userdata = ReadMemory<uint32_t>({lawn, user_data});
    if (userdata == 0) // 还没建立用户
        return;

    // Adventure
    uint32_t adventure_playthrough =ReadMemory<uint32_t>({ userdata+0x2c});
    if (adventure_playthrough < 2)
        WriteMemory<uint32_t>(2, {userdata+0x2c});

    // Mini-games
    for (size_t i = 0; i < 33; i++)
        if (ReadMemory<int>({userdata+0x6c + i * 4}) == 0)
            WriteMemory<int>(1,{userdata+0x6c + i * 4});

    // Vasebreaker
    for (size_t i = 0; i < 9; i++)
        if (ReadMemory<int>({userdata+ 0xf8 + i * 4}) == 0)
            WriteMemory<int>(1, {userdata+ 0xf8 + i * 4});

    // I, Zombie
    for (size_t i = 0; i < 9; i++)
        if (ReadMemory<int>({userdata+ 0x120 + i * 4}) == 0)
            WriteMemory<int>(1, {userdata+ 0x120 + i * 4});

    // Survival
    for (size_t i = 0; i < 5; i++)
        if (ReadMemory<int>({userdata+ 0x30 + i * 4}) != 5)
            WriteMemory<int>(5, {userdata+ 0x30 + i * 4});

    // Survival Hard
    for (size_t i = 0; i < 5; i++)
        if (ReadMemory<int>({userdata+ 0x44 + i * 4}) != 10)
            WriteMemory<int>(10, {userdata+ 0x44 + i * 4});

    if (GetGameUI() == 1)
    {
        CodeStruct* newcode=Init();
        PushByte(newcode,1); // 显示 Loading
        MovRegDwordptr(newcode,Reg::ECX, 0x6a9ec0);
        MovRegDwordptrOff(newcode,Reg::ECX, 0x770);
        Call(newcode,0x0044a320);
        Ret(newcode);
        CodeInject(pvzHand,newcode);
    }
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 结束设置解锁金向日葵\n").arg(currentTime);
    }
}

void PassGame()
{
    if (CheckGameOn() && GetGameUI() == 3)
    {
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 开始设置直接过关\n").arg(currentTime);
        }
        CodeStruct* newcode=Init();
        MovRegDwordptr(newcode,Reg::ECX, 0x6a9ec0);
        MovRegDwordptrOff(newcode,Reg::ECX, 0x768);
        Call(newcode,0x0040c3e0);
        Ret(newcode);
        CodeInject(pvzHand,newcode);
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 结束设置直接过关\n").arg(currentTime);
        }
    }
}

void HideShovel(bool on)
{
    if (CheckGameOn() && (GetGameUI() == 2 || GetGameUI() == 3))
    {
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 开始设置隐藏铲子\n").arg(currentTime);
        }
        if (on)
            WriteMemory<bool>(false, {0x6a9ec0, 0x768, 0x55f1});
        else
            WriteMemory<bool>(true,{ 0x6a9ec0, 0x768, 0x55f1});
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 结束设置隐藏铲子\n").arg(currentTime);
        }
    }
}

void HideMenu(bool on)
{
    if (CheckGameOn())
    {
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 开始设置隐藏菜单按钮\n").arg(currentTime);
        }
        int ui = GetGameUI();
        if (on)
        {
            WriteMemory<bool>(true, {0x0043b9e0});
            WriteMemory<bool>(true, {0x0043c39f});
            if (ui == 2)
                WriteMemory<bool>(true,{ 0x6a9ec0, 0x774, 0x9c, 0xf9});
            else if (ui == 3)
                WriteMemory<bool>(true, {0x6a9ec0, 0x768, 0x148, 0xf9});
        }
        else
        {
            WriteMemory<bool>(false, {0x0043b9e0});
            WriteMemory<bool>(false, {0x0043c39f});
            if (ui == 2)
                WriteMemory<bool>(false, {0x6a9ec0, 0x774, 0x9c, 0xf9});
            else if (ui == 3)
                WriteMemory<bool>(false, {0x6a9ec0, 0x768, 0x148, 0xf9});
        }
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 结束设置隐藏菜单按钮\n").arg(currentTime);
        }
    }
}

void SetNoSun(bool on)
{
    if (CheckGameOn())
    {
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 开始设置不掉阳光\n").arg(currentTime);
        }
        if(on) WriteMemory<uint8_t>(0xeb, {0x00413B83});
        else WriteMemory<uint8_t>(0x75, {0x00413B83});
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 结束设置不掉阳光\n").arg(currentTime);
        }
    }
}

void AutoCollect(bool on)
{
    if (CheckGameOn())
    {
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 开始设置自动收集\n").arg(currentTime);
        }
        if (on)
        {
            WriteMemory<uint8_t>(0xeb, {0x0043158f});
        }
        else
        {
            WriteMemory<uint8_t>(0x75, {0x0043158f});
        }
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 结束设置自动收集\n").arg(currentTime);
        }
    }
}

void ZombieInvincible(bool on)
{
    if (!CheckGameOn())
        return;
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 开始设置僵尸无敌\n").arg(currentTime);
    }
    if(on) WriteMemory(zombie_immune_body_damage.hack_value,{zombie_immune_body_damage.mem_addr});
    else WriteMemory(zombie_immune_body_damage.reset_value,{zombie_immune_body_damage.mem_addr});

    if(on) WriteMemory(zombie_immune_helm_damage.hack_value,{zombie_immune_helm_damage.mem_addr});
    else WriteMemory(zombie_immune_helm_damage.reset_value,{zombie_immune_helm_damage.mem_addr});

    if(on) WriteMemory(zombie_immune_shield_damage.hack_value,{zombie_immune_shield_damage.mem_addr});
    else WriteMemory(zombie_immune_shield_damage.reset_value,{zombie_immune_shield_damage.mem_addr});

    if(on) WriteMemory(zombie_immune_burn_crumble.hack_value,{zombie_immune_burn_crumble.mem_addr});
    else WriteMemory(zombie_immune_burn_crumble.reset_value,{zombie_immune_burn_crumble.mem_addr});

    if(on) WriteMemory(zombie_immune_radius.hack_value,{zombie_immune_radius.mem_addr});
    else WriteMemory(zombie_immune_radius.reset_value,{zombie_immune_radius.mem_addr});

    if(on) WriteMemory(zombie_immune_burn_row.hack_value,{zombie_immune_burn_row.mem_addr});
    else WriteMemory(zombie_immune_burn_row.reset_value,{zombie_immune_burn_row.mem_addr});

    if(on) WriteMemory(zombie_immune_chomper.hack_value,{zombie_immune_chomper.mem_addr});
    else WriteMemory(zombie_immune_chomper.reset_value,{zombie_immune_chomper.mem_addr});

    if(on) WriteMemory(zombie_immune_mind_controll.hack_value,{zombie_immune_mind_controll.mem_addr});
    else WriteMemory(zombie_immune_mind_controll.reset_value,{zombie_immune_mind_controll.mem_addr});

    if(on) WriteMemory(zombie_immune_blow_away.hack_value,{zombie_immune_blow_away.mem_addr});
    else WriteMemory(zombie_immune_blow_away.reset_value,{zombie_immune_blow_away.mem_addr});

    if(on) WriteMemory(zombie_immune_splash.hack_value,{zombie_immune_splash.mem_addr});
    else WriteMemory(zombie_immune_splash.reset_value,{zombie_immune_splash.mem_addr});

    if(on) WriteMemory(zombie_immune_lawn_mower.hack_value,{zombie_immune_lawn_mower.mem_addr});
    else WriteMemory(zombie_immune_lawn_mower.reset_value,{zombie_immune_lawn_mower.mem_addr});
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 结束设置僵尸无敌\n").arg(currentTime);
    }
}

void MushroomNoSleep(bool on)
{
    if (!CheckGameOn())
        return;
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 开始设置蘑菇免唤醒\n").arg(currentTime);
    }
    if(on) WriteMemory(mushrooms_awake.hack_value,{mushrooms_awake.mem_addr});
    else WriteMemory(mushrooms_awake.reset_value,{mushrooms_awake.mem_addr});

    int ui = GetGameUI();
    if (ui != 2 && ui != 3)
        return;

    unsigned int plant_struct_size = 0x14c;

    if (on)
    {
        auto Plant_count_max = ReadMemory<uint32_t>({lawn, board, plant_count_max});
        auto Plant_offset = ReadMemory<uintptr_t>({lawn, board, plant_offset});
        CodeStruct* newcode=Init();
        for (size_t i = 0; i < Plant_count_max; i++)
        {
            auto Plant_dead = ReadMemory<bool>({Plant_offset + plant_dead + plant_struct_size * i});
            auto Plant_squished = ReadMemory<bool>({Plant_offset + plant_squished + plant_struct_size * i});
            auto Plant_asleep = ReadMemory<bool>({Plant_offset + plant_asleep + plant_struct_size * i});
            if (!Plant_dead && !Plant_squished && Plant_asleep)
            {
                uint32_t addr = Plant_offset + plant_struct_size * i;
                MovReg(newcode,Reg::EAX, addr);
                PushByte(newcode,0);
                Call(newcode,0x0045e860);
            }
        }
        Ret(newcode);
        CodeInject(pvzHand,newcode);
    }
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 结束设置蘑菇免唤醒\n").arg(currentTime);
    }
}

void StopZombieMove(bool on)
{
    if (!CheckGameOn())
        return;
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 开始设置僵尸不动\n").arg(currentTime);
    }
    for (size_t i = 0; i < stop_zombies.size(); i++){
        if(on) WriteMemory(stop_zombies[i].hack_value,{stop_zombies[i].mem_addr});
        else WriteMemory(stop_zombies[i].reset_value,{stop_zombies[i].mem_addr});
    }
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 结束设置僵尸不动\n").arg(currentTime);
    }
}

void StopSystemZombie(bool on)
{
    if (!CheckGameOn())
        return;
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 开始设置暂停系统出怪\n").arg(currentTime);
    }
    if(on) WriteMemory(stop_spawning.hack_value,{stop_spawning.mem_addr});
    else WriteMemory(stop_spawning.reset_value,{stop_spawning.mem_addr});
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 结束设置暂停系统出怪\n").arg(currentTime);
    }
}

void NoCrater(bool on)
{
    if (!CheckGameOn())
        return;
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 开始设置不留弹坑\n").arg(currentTime);
    }
    if(on) WriteMemory(no_crater.hack_value,{no_crater.mem_addr});
    else WriteMemory(no_crater.reset_value,{no_crater.mem_addr});
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 结束设置不留弹坑\n").arg(currentTime);
    }
}

void AllowBackRunning(bool on)
{
    if (!CheckGameOn())
        return;
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 开始设置后台运行\n").arg(currentTime);
    }
    if(on) WriteMemory(background_running.hack_value,{background_running.mem_addr});
    else WriteMemory(background_running.reset_value,{background_running.mem_addr});
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 结束设置后台运行\n").arg(currentTime);
    }
}

void PlaceNoCD(bool on)
{
    if (CheckGameOn())
    {
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 开始设置卡片无冷却\n").arg(currentTime);
        }
        if (on)
        {
            WriteMemory<uint8_t>(0x70, {0x00487296});
            WriteMemory<uint8_t>(0xeb, {0x00488250});
        }
        else
        {
            WriteMemory<uint8_t>(0x7e, {0x00487296});
            WriteMemory<uint8_t>(0x75, {0x00488250});
        }
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 结束设置卡片无冷却\n").arg(currentTime);
        }
    }
}

void IgnoreSun(bool on)
{
    if (CheckGameOn())
    {
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 开始设置不消耗阳光\n").arg(currentTime);
        }
        if (on)
        {
            WriteMemory<uint8_t>(0x70, {0x0041ba72});
            WriteMemory<uint8_t>(0x3b, {0x0041ba74});
            WriteMemory<uint8_t>(0x91, {0x0041bac0});
            WriteMemory<uint8_t>(0x80, {0x00427a92});
            WriteMemory<uint8_t>(0x80, {0x00427dfd});
            WriteMemory<uint8_t>(0xeb, {0x0042487f});
        }
        else
        {
            WriteMemory<uint8_t>(0x7f, {0x0041ba72});
            WriteMemory<uint8_t>(0x2b, {0x0041ba74});
            WriteMemory<uint8_t>(0x9e, {0x0041bac0});
            WriteMemory<uint8_t>(0x8f, {0x00427a92});
            WriteMemory<uint8_t>(0x8f, {0x00427dfd});
            WriteMemory<uint8_t>(0x74, {0x0042487f});
        }
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 结束设置不消耗阳光\n").arg(currentTime);
        }
    }
}

void PurpleSeedUnlimited(bool on)
{
    if (CheckGameOn())
    {
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 开始设置紫卡无限制\n").arg(currentTime);
        }
        if (on)
        {
            WriteMemory(std::array<uint8_t, 3>{0xb0, 0x01, 0xc3}, {0x0041d7d0});
            WriteMemory<uint8_t>(0xeb, {0x0040e477});
        }
        else
        {
            WriteMemory(std::array<uint8_t, 3>{0x51, 0x83, 0xf8}, {0x0041d7d0});
            WriteMemory<uint8_t>(0x74, {0x0040e477});
        }
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 结束设置紫卡无限制\n").arg(currentTime);
        }
    }
}

bool CompareVerinfo() {
    if(!CheckGameOn()) return false;
    TCHAR szFilePath[MAX_PATH];
    if(!GetModuleFileNameEx(pvzHand, NULL, szFilePath, MAX_PATH)){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        if(out.device()!=nullptr)out << QString("[%1] Error: 获取进程所在路径名错误，错误码：%2.\n").arg(currentTime).arg(GetLastError());
        return false;
    }
    QString filepath=QString::fromWCharArray(szFilePath);
    QString productName = GetExeProductName(filepath);
    if(productName!="Plants vs. Zombies"){
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] %2不是一个植物大战僵尸游戏，其产品名称为：%3\n").arg(currentTime).arg(filepath).arg(productName);
        }
        return false;
    }
    QString verinfo=GetExeFileVersion(filepath);
    if(verinfo=="1.0.0.1051"){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        if(out.device()!=nullptr)out << QString("[%1] Success: 当前版本支持：%2\n").arg(currentTime).arg(verinfo);
        return true;
    }
    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
    if(out.device()!=nullptr)out << QString("[%1] Failed: 当前不版本支持：%2\n").arg(currentTime).arg(verinfo);
    return false;
}

QString GetExeFileVersion(const QString& filePath) {
    DWORD dwDummy;
    DWORD dwSize = GetFileVersionInfoSize(filePath.toStdWString().c_str(), &dwDummy);
    if (dwSize == 0) {
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        if(out.device()!=nullptr)out << QString("[%1] Error: 获取文件版本信息大小失败，错误码：%2.\n").arg(currentTime).arg(GetLastError());
        return QString();
    }

    std::vector<BYTE> versionInfoBuffer(dwSize);
    if (!GetFileVersionInfo(filePath.toStdWString().c_str(), 0, dwSize, versionInfoBuffer.data())) {
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        if(out.device()!=nullptr)out << QString("[%1] Error: 获取文件版本信息失败，错误码：%2.\n").arg(currentTime).arg(GetLastError());
        return QString();
    }

    LPVOID lpBuffer = NULL;
    UINT uLen;
    if (VerQueryValue(versionInfoBuffer.data(), L"\\", &lpBuffer, &uLen)) {
        VS_FIXEDFILEINFO* fileInfo = static_cast<VS_FIXEDFILEINFO*>(lpBuffer);
        QString version = QString::number(HIWORD(fileInfo->dwFileVersionMS)) + "." +
                          QString::number(LOWORD(fileInfo->dwFileVersionMS)) + "." +
                          QString::number(HIWORD(fileInfo->dwFileVersionLS)) + "." +
                          QString::number(LOWORD(fileInfo->dwFileVersionLS));
        return version;
    } else {
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        if(out.device()!=nullptr)out << QString("[%1] Error: 解析文件版本信息失败，错误码：%2.\n").arg(currentTime).arg(GetLastError());
        return QString();
    }
}

QString GetExeProductName(const QString &filePath)
{
    DWORD dummy;
    DWORD versionSize = GetFileVersionInfoSize(filePath.toStdWString().c_str(), &dummy);
    if (versionSize == 0) {
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        if(out.device()!=nullptr)out << QString("[%1] Error: Failed to get version info size, error code: %2.\n").arg(currentTime).arg(GetLastError());
        return QString();
    }

    std::vector<BYTE> versionData(versionSize);
    if (!GetFileVersionInfo(filePath.toStdWString().c_str(), 0, versionSize, versionData.data())) {
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        if(out.device()!=nullptr)out << QString("[%1] Error: Failed to get version info, error code: %2.\n").arg(currentTime).arg(GetLastError());
        return QString();
    }

    VS_FIXEDFILEINFO *fileInfo;
    UINT fileInfoSize;
    if (!VerQueryValue(versionData.data(), L"\\", reinterpret_cast<LPVOID*>(&fileInfo), &fileInfoSize)) {
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
       if(out.device()!=nullptr)out << QString("[%1] Error: Failed to query version info, error code: %2.\n").arg(currentTime).arg(GetLastError());
        return QString();
    }

    // Check if the product name exists in the version info
    WCHAR *productName;
    UINT productNameSize;
    if (!VerQueryValue(versionData.data(), L"\\StringFileInfo\\040904B0\\ProductName", reinterpret_cast<LPVOID*>(&productName), &productNameSize)) {
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        if(out.device()!=nullptr)out << QString("[%1] Product name not found in version info.\n").arg(currentTime);
        return QString();
    }

    return QString::fromWCharArray(productName);
}

QStringList GetPlantBook()
{
    //暂时还做不到自动获取……
    return QStringList();
}

void OverlapPlant(bool on)
{
    if (CheckGameOn())
    {
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 开始设置重叠放置\n").arg(currentTime);
        }
        if (on)
        {
            WriteMemory<uint8_t>(0x81, {0x0040fe30});
        }
        else
        {
            WriteMemory<uint8_t>(0x84, {0x0040fe30});
        }
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 结束设置重叠放置\n").arg(currentTime);
        }
    }
}

void ChangeBaseValue(uint32_t addr,uint32_t value,bool isbyte)
{
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 开始修改基础数值\n").arg(currentTime);
    }
    if (isbyte)
    {
        WriteMemory<uint8_t>(value, {addr});
    }
    else
    {
        WriteMemory<uint32_t>(value, {addr});
    }
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 结束修改基础数值\n").arg(currentTime);
    }
}

void UnlockMaxMemory()
{
    CodeStruct *newcode=Init();
    MovReg(newcode,Reg::ESI,4096);
    for(size_t i=0;i<newcode->length;i++){
        WriteMemory<uint8_t>(newcode->code[i],{0x407cbc+i});//size
    }

    newcode=Init();
    PushDword(newcode,4096*0x14c);//植物上限
    for(size_t i=0;i<newcode->length;i++){
        WriteMemory<uint8_t>(newcode->code[i],{0x407cc1+i});
    }

    newcode=Init();
    PushDword(newcode,4096*0x15c);//僵尸上限
    for(size_t i=0;i<newcode->length;i++){
        WriteMemory<uint8_t>(newcode->code[i],{0x407ca9+i});
    }

    newcode=Init();
    PushDword(newcode,40960*0x94);//子弹上限
    for(size_t i=0;i<newcode->length;i++){
        WriteMemory<uint8_t>(newcode->code[i],{0x407d04+i});
    }
}

void ResumeMaxMemory()
{
    CodeStruct *newcode=Init();
    MovReg(newcode,Reg::ESI,4096);
    for(size_t i=0;i<newcode->length;i++){
        WriteMemory<uint8_t>(newcode->code[i],{0x407cbc+i});//size
    }

    newcode=Init();
    PushDword(newcode,4096*0x14c);//植物上限
    for(size_t i=0;i<newcode->length;i++){
        WriteMemory<uint8_t>(newcode->code[i],{0x407cc1+i});
    }

    newcode=Init();
    PushDword(newcode,4096*0x15c);//僵尸上限
    for(size_t i=0;i<newcode->length;i++){
        WriteMemory<uint8_t>(newcode->code[i],{0x407ca9+i});
    }

    newcode=Init();
    PushDword(newcode,40960*0x94);//子弹上限
    for(size_t i=0;i<newcode->length;i++){
        WriteMemory<uint8_t>(newcode->code[i],{0x407d04+i});
    }
}
void UnlockShopItems(bool on)
{
    uint32_t userdataaddr=ReadMemory<uint32_t>({lawn,0x82c});
    if(on){
        WriteMemory<bool>(true, {userdataaddr+ 0x1c0}); // Gatling Pea
        WriteMemory<bool>(true, {userdataaddr+ 0x1c4}); // Twin Sunflower
        WriteMemory<bool>(true, {userdataaddr+ 0x1c8}); // Gloom-shroom
        WriteMemory<bool>(true, {userdataaddr+ 0x1cc}); // Cattail
        WriteMemory<bool>(true, {userdataaddr+ 0x1d0}); // Winter Melon
        WriteMemory<bool>(true, {userdataaddr+ 0x1d4}); // Gold Magnet
        WriteMemory<bool>(true, {userdataaddr+ 0x1d8}); // Spikerock
        WriteMemory<bool>(true, {userdataaddr+ 0x1dc}); // Cob Cannon

        WriteMemory<bool>(true, {userdataaddr+ 0x1e0}); // Imitater
        WriteMemory<bool>(true, {userdataaddr+ 0x234}); // Wall-nut First Aid

        WriteMemory<uint32_t>(4, {userdataaddr+ 0x214}); // 10 seed slots
        WriteMemory<bool>(true, {userdataaddr+ 0x218}); // Pool Cleaner
        WriteMemory<bool>(true, {userdataaddr+ 0x21c}); // Roof Cleaner

        WriteMemory<int>(4, {userdataaddr+ 0x1e8});        // Marigold Sprout #1
        WriteMemory<int>(4, {userdataaddr+ 0x1ec});        // Marigold Sprout #2
        WriteMemory<int>(4, {userdataaddr+ 0x1f0});        // Marigold Sprout #3
        WriteMemory<bool>(true, {userdataaddr+ 0x1f4});        // Golden Watering Can
        if (ReadMemory<uint32_t>({userdataaddr+ 0x1f8}) == 0)   //
            WriteMemory<uint32_t>(1020, {userdataaddr+ 0x1f8}); // Fertilizer 20->1020
        if (ReadMemory<uint32_t>({userdataaddr+ 0x1fc}) == 0)   //
            WriteMemory<uint32_t>(1020, {userdataaddr+ 0x1fc}); // Bug Spray 20->1020
        WriteMemory<bool>(true, {userdataaddr+ 0x200});        // Phonograph
        WriteMemory<bool>(true, {userdataaddr+ 0x204});        // Gardening Glove

        WriteMemory<bool>(true, {userdataaddr+ 0x208});        // Mushroom Garden
        WriteMemory<bool>(true, {userdataaddr+ 0x224});        // Aquarium Garden
        WriteMemory<bool>(true, {userdataaddr+ 0x22c});        // Tree of Wisdom
        if (ReadMemory<uint32_t>({userdataaddr+ 0x230}) == 0)   //
            WriteMemory<uint32_t>(1010, {userdataaddr+ 0x230}); // Tree Food 10->1010
        WriteMemory<bool>(true, {userdataaddr+ 0x20c});        // Wheel Barrow
        WriteMemory<bool>(true, {userdataaddr+ 0x210});        // Snail
        if (ReadMemory<uint32_t>({userdataaddr+ 0x228}) == 0)   //
            WriteMemory<uint32_t>(1010, {userdataaddr+ 0x228});
    }
    else{
        WriteMemory<bool>(false, {userdataaddr+ 0x1c0}); // Gatling Pea
        WriteMemory<bool>(false, {userdataaddr+ 0x1c4}); // Twin Sunflower
        WriteMemory<bool>(false, {userdataaddr+ 0x1c8}); // Gloom-shroom
        WriteMemory<bool>(false, {userdataaddr+ 0x1cc}); // Cattail
        WriteMemory<bool>(false, {userdataaddr+ 0x1d0}); // Winter Melon
        WriteMemory<bool>(false, {userdataaddr+ 0x1d4}); // Gold Magnet
        WriteMemory<bool>(false, {userdataaddr+ 0x1d8}); // Spikerock
        WriteMemory<bool>(false, {userdataaddr+ 0x1dc}); // Cob Cannon

        WriteMemory<bool>(false, {userdataaddr+ 0x1e0}); // Imitater
        WriteMemory<bool>(false, {userdataaddr+ 0x234}); // Wall-nut First Aid

        WriteMemory<uint32_t>(0, {userdataaddr+ 0x214}); // 10 seed slots
        WriteMemory<bool>(false, {userdataaddr+ 0x218}); // Pool Cleaner
        WriteMemory<bool>(false, {userdataaddr+ 0x21c}); // Roof Cleaner

        WriteMemory<int>(0, {userdataaddr+ 0x1e8});        // Marigold Sprout #1
        WriteMemory<int>(0, {userdataaddr+ 0x1ec});        // Marigold Sprout #2
        WriteMemory<int>(0, {userdataaddr+ 0x1f0});        // Marigold Sprout #3
        WriteMemory<bool>(false, {userdataaddr+ 0x1f4});        // Golden Watering Can
        WriteMemory<uint32_t>(0, {userdataaddr+ 0x1f8}); // Fertilizer 20->1020
        WriteMemory<uint32_t>(0, {userdataaddr+ 0x1fc}); // Bug Spray 20->1020
        WriteMemory<bool>(false, {userdataaddr+ 0x200});        // Phonograph
        WriteMemory<bool>(false, {userdataaddr+ 0x204});        // Gardening Glove

        WriteMemory<bool>(false, {userdataaddr+ 0x208});        // Mushroom Garden
        WriteMemory<bool>(false, {userdataaddr+ 0x224});        // Aquarium Garden
        WriteMemory<bool>(false, {userdataaddr+ 0x22c});        // Tree of Wisdom
        WriteMemory<uint32_t>(0, {userdataaddr+ 0x230}); // Tree Food 10->1010
        WriteMemory<bool>(false, {userdataaddr+ 0x20c});        // Wheel Barrow
        WriteMemory<bool>(false, {userdataaddr+ 0x210});        // Snail
        WriteMemory<uint32_t>(0, {userdataaddr+ 0x228});
    }
}

void ClearAllBullet()
{
    WriteMemory(block_main_loop.hack_value,{block_main_loop.mem_addr});
    uint32_t bulletoff=ReadMemory<uint32_t>({lawn,board,bullet_offset});
    uint32_t bulletmax=ReadMemory<uint32_t>({lawn,board,bullet_count_max});
    for(size_t i=0;i<bulletmax;i++){
        WriteMemory<bool>(true,{bulletoff+bullet_disappear+bullet_single_size*i});
    }
    WriteMemory(block_main_loop.reset_value,{block_main_loop.mem_addr});
}
