#include "gameinfo.h"
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
    int check=GetProcessId(PvzName);
    if(check) return true;
    return false;
}

bool CheckBoardOn()
{
    auto check=ReadMemory<uint32_t>({lawn,board});
    if(check) return true;
    return false;
}

void Resumemower()
{
    Clearmower(0);
    WriteMemory(init_lawn_mower.hack_value,{init_lawn_mower.mem_addr});
    WriteMemory(lawn_mower_initialize.hack_value,{lawn_mower_initialize.mem_addr});
    CodeStruct* resumecode=Init();
    MovRegDwordptr(resumecode,Reg::EAX,lawn);
    MovRegDwordptrOff(resumecode,Reg::EAX,board);
    PushReg(resumecode,Reg::EAX);
    Call(resumecode,call_restore_lawn_mower);
    Ret(resumecode);
    CodeInject(resumecode);
}

void Startmower(int row)
{
    uint32_t moweroffset=ReadMemory<uint32_t>({lawn,board,lawn_mower});
    auto maxmower=ReadMemory<uint32_t>({lawn,board,lawn_mower_current_count});
    for(int i=0;i<maxmower;i++)
    {
        auto lawn_mower_dead = ReadMemory<bool>({moweroffset + lawn_mower_isfalse + lawn_mower_next * i});

        if(row==0&&!lawn_mower_dead){
            CodeStruct* startcode=Init();
            MovReg(startcode,Reg::ESI,moweroffset+lawn_mower_next*i);
            Call(startcode,call_start_lawn_mower);
            Ret(startcode);
            CodeInject(startcode);
            //WriteMemory<uint32_t>(2,{moweroffset+lawn_mower_state+lawn_mower_next*i});
        }
        else if(!lawn_mower_dead&&row!=0){
            auto mowerrow=ReadMemory<uint32_t>({moweroffset+lawn_mower_row+lawn_mower_next*i});
            if(row-1!=mowerrow) continue;
            CodeStruct* startcode=Init();
            MovReg(startcode,Reg::ESI,moweroffset+lawn_mower_next*i);
            Call(startcode,call_start_lawn_mower);
            Ret(startcode);
            CodeInject(startcode);
            //WriteMemory<uint32_t>(2,{moweroffset+lawn_mower_state+lawn_mower_next*i});
        }
    }
}

void Clearmower(int row)
{
    uint32_t moweroffset=ReadMemory<uint32_t>({lawn,board,lawn_mower});
    auto maxmower=ReadMemory<uint32_t>({lawn,board,lawn_mower_count_max});
    for(int i=0;i<maxmower;i++)
    {
        auto lawn_mower_dead = ReadMemory<bool>({moweroffset + lawn_mower_isfalse + lawn_mower_next * i});
        auto mowerrow=ReadMemory<uint32_t>({moweroffset+lawn_mower_row+lawn_mower_next*i});
        if(row==0&&!lawn_mower_dead){
            CodeStruct* clearcode=Init();
            MovReg(clearcode,Reg::EAX,moweroffset+lawn_mower_next*i);
            Call(clearcode,call_delete_lawn_mower);
            Ret(clearcode);
            CodeInject(clearcode);
            //WriteMemory<uint32_t>(3,{moweroffset+lawn_mower_state+lawn_mower_next*i});
        }
        else if(!lawn_mower_dead&&row!=0){
            auto mowerrow=ReadMemory<uint32_t>({moweroffset+lawn_mower_row+lawn_mower_next*i});
            if(row-1!=mowerrow) continue;
            CodeStruct* clearcode=Init();
            MovReg(clearcode,Reg::EAX,moweroffset+lawn_mower_next*i);
            Call(clearcode,call_delete_lawn_mower);
            Ret(clearcode);
            CodeInject(clearcode);
        }
    }
}

void SetGamePause()
{
    auto isGamePaused=ReadMemory<bool>({lawn,board,game_pause});
    WriteMemory<bool>(!isGamePaused,{lawn,board,game_pause});
}

void PlantNoLimit(bool on)
{
    if(on) WriteMemory(placed_anywhere.hack_value,{placed_anywhere.mem_addr});
    else WriteMemory(placed_anywhere.reset_value,{placed_anywhere.mem_addr});
    if(on) WriteMemory(placed_anywhere_preview.hack_value,{placed_anywhere_preview.mem_addr});
    else WriteMemory(placed_anywhere_preview.reset_value,{placed_anywhere_preview.mem_addr});
    if(on) WriteMemory(placed_anywhere_iz.hack_value,{placed_anywhere_iz.mem_addr});
    else WriteMemory(placed_anywhere_iz.reset_value,{placed_anywhere_iz.mem_addr});
}

void LockShovel(bool on)
{
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
}

void PlantInvincible(bool on)
{
    //这一段有问题，会导致游戏崩溃。暂且不用
    // if(on) WriteMemory(plant_immune_eat.hack_value,{plant_immune_eat.mem_addr});
    //else WriteMemory(plant_immune_eat.reset_value,{plant_immune_eat.mem_addr});

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
}

void UnlockAllMode(bool on)
{
    if (CheckGameOn())
    {
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
            CodeInject(newcode);
        }
    }
}

void UnlockGoldFlower(bool on)
{
    if (!CheckGameOn())
        return;

    auto userdata = ReadMemory<uintptr_t>({lawn, user_data});
    if (userdata == 0) // 还没建立用户
        return;

    auto Playthrough = userdata + playthrough;

    // Adventure
    int adventure_playthrough = ReadMemory<int>({Playthrough});
    if (adventure_playthrough < 2)
        WriteMemory<int>(2, {Playthrough});
    Playthrough += 1 * sizeof(int);

    ///

    auto Mini_games = userdata + mini_games;

    // Survival
    // Survival Hard
    WriteMemory<int, 5 + 5>({5, 5, 5, 5, 5, 10, 10, 10, 10, 10}, {Mini_games});
    Mini_games += (5 + 5) * sizeof(int);

    // Survival Endless
    Mini_games += 5 * sizeof(int);

    // Mini-games
    WriteMemory<int, 20>({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {Mini_games});

    Mini_games += 20 * sizeof(int);

    // Hidden Mini-games
    // Squirrel
    Mini_games += (13 + 1) * sizeof(int);

    // Wisdom Tree (Height)

    // Vasebreaker
    WriteMemory<int, 9>({1, 1, 1, 1, 1, 1, 1, 1, 1}, {Mini_games});
    Mini_games += 9 * sizeof(int);

    // Vasebreaker Endless
    Mini_games += 1 * sizeof(int);

    // I, Zombie
    WriteMemory<int, 9>({1, 1, 1, 1, 1, 1, 1, 1, 1}, {Mini_games});
    Mini_games += 9 * sizeof(int);

    // I, Zombie Endless
    Mini_games += 1 * sizeof(int);

    ////

    auto Twiddydinky = userdata + twiddydinky;

    // Gatling Pea
    // Twin Sunflower
    // Gloom-shroom
    // Cattail
    // Winter Melon
    // Gold Magnet
    // Spikerock
    // Cob Cannon
    WriteMemory<int, 8>({1, 1, 1, 1, 1, 1, 1, 1}, {Twiddydinky});
    Twiddydinky += 8 * sizeof(int);

    // Imitater
    WriteMemory<int>(1, {twiddydinky});
    Twiddydinky += 1 * sizeof(int);

    // unknown
    // Marigold Sprout x3
    // Golden Watering Can
    // Fertilizer
    // Bug Spray
    // Phonograph
    // Gardening Glove
    // Mushroom Garden
    // Wheel Barrow
    // Snail
    Twiddydinky += (1 + 3 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1) * sizeof(int);

    // 6+4 seed slots
    WriteMemory<int>(4, {Twiddydinky});
    Twiddydinky += 1 * sizeof(int);

    // Pool Cleaner
    WriteMemory<int>(1, {Twiddydinky});
    Twiddydinky += 1 * sizeof(int);

    // Roof Cleaner
    WriteMemory<int>(1, {Twiddydinky});
    Twiddydinky += 1 * sizeof(int);

    // Garden Rake
    // Aquarium Garden
    // Chocolate
    Twiddydinky += (1 + 1 + 1) * sizeof(int);

        if (GetGameUI() == 1)
        {
            CodeStruct* newcode=Init();
            PushByte(newcode,1); // 显示 Loading
            MovRegDwordptr(newcode,Reg::ECX, 0x6a9ec0);
            MovRegDwordptrOff(newcode,Reg::ECX, 0x770);
            Call(newcode,0x0044a320);
            Ret(newcode);
            CodeInject(newcode);
        }
}

void PassGame()
{
    if (CheckGameOn() && GetGameUI() == 3)
    {
        CodeStruct* newcode=Init();
        MovRegDwordptr(newcode,Reg::ECX, 0x6a9ec0);
        MovRegDwordptrOff(newcode,Reg::ECX, 0x768);
        Call(newcode,0x0040c3e0);
        Ret(newcode);
        CodeInject(newcode);
    }
}

void HideShovel(bool on)
{
    if (CheckGameOn() && (GetGameUI() == 2 || GetGameUI() == 3))
    {
        if (on)
            WriteMemory<bool>(false, {0x6a9ec0, 0x768, 0x55f1});
        else
            WriteMemory<bool>(true,{ 0x6a9ec0, 0x768, 0x55f1});
    }
}

void HideMenu(bool on)
{
    if (CheckGameOn())
    {
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
    }
}

void SetNoSun(bool on)
{
    if (CheckGameOn())
    {
        if(on) WriteMemory<uint8_t>(0xeb, {0x00413B83});
        else WriteMemory<uint8_t>(0x75, {0x00413B83});
    }
}

void AutoCollect(bool on)
{
    if (CheckGameOn())
    {
        if (on)
        {
            WriteMemory<uint8_t>(0xeb, {0x0043158f});
        }
        else
        {
            WriteMemory<uint8_t>(0x75, {0x0043158f});
        }
    }
}

void ZombieInvincible(bool on)
{
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
}

void MushroomNoSleep(bool on)
{
    if (!CheckGameOn())
        return;

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
        for (size_t i = 0; i < Plant_count_max; i++)
        {
            auto Plant_dead = ReadMemory<bool>({Plant_offset + plant_dead + plant_struct_size * i});
            auto Plant_squished = ReadMemory<bool>({Plant_offset + plant_squished + plant_struct_size * i});
            auto Plant_asleep = ReadMemory<bool>({Plant_offset + plant_asleep + plant_struct_size * i});
            if (!Plant_dead && !Plant_squished && Plant_asleep)
            {
                uint32_t addr = Plant_offset + plant_struct_size * i;
                WriteMemory<bool>(false,{addr+plant_asleep});
            }
        }
    }
}

void StopZombieMove(bool on)
{
    if (!CheckGameOn())
        return;
    for (size_t i = 0; i < stop_zombies.size(); i++){
        if(on) WriteMemory(stop_zombies[i].hack_value,{stop_zombies[i].mem_addr});
        else WriteMemory(stop_zombies[i].reset_value,{stop_zombies[i].mem_addr});
    }
}

void StopSystemZombie(bool on)
{
    if (!CheckGameOn())
        return;
    if(on) WriteMemory(stop_spawning.hack_value,{stop_spawning.mem_addr});
    else WriteMemory(stop_spawning.reset_value,{stop_spawning.mem_addr});
}

void NoCrater(bool on)
{
    if (!CheckGameOn())
        return;
    if(on) WriteMemory(no_crater.hack_value,{no_crater.mem_addr});
    else WriteMemory(no_crater.reset_value,{no_crater.mem_addr});
}

void AllowBackRunning(bool on)
{
    if (!CheckGameOn())
        return;
    if(on) WriteMemory(background_running.hack_value,{background_running.mem_addr});
    else WriteMemory(background_running.reset_value,{background_running.mem_addr});
}

void PlaceNoCD(bool on)
{
    if (CheckGameOn())
    {
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
    }
}

void IgnoreSun(bool on)
{
    if (CheckGameOn())
    {
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
    }
}

void PurpleSeedUnlimited(bool on)
{
    if (CheckGameOn())
    {
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
    }
}
