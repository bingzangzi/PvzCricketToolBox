#include "plant_formation.h"



const char* plant[48] = {
    "豌豆射手","向日葵","樱桃炸弹","坚果","土豆雷","寒冰射手","大嘴花","双发射手",
    "小喷菇","阳光菇","大喷菇","墓碑吞噬者","魅惑菇","胆小菇","寒冰菇","毁灭菇",
    "睡莲","窝瓜","三线射手","缠绕海草","火爆辣椒","地刺","火炬","高坚果",
    "海蘑菇","路灯花","仙人掌","三叶草","裂荚射手","杨桃","南瓜头","磁力菇",
    "卷心菜投手","花盆","玉米投手","咖啡豆","大蒜","叶子保护伞","金盏花","西瓜投手",
    "机枪射手","双子向日葵","忧郁蘑菇","香蒲","冰西瓜投手","吸金磁","地磁王","玉米加农炮"
}; //原版图鉴植物
int MaxCol;//列
int MaxRow;//行
bool plantIfAllow[48];//设定的有用植物判断
bool plantIfGift[48];//设定的附赠的植物判断，如睡莲、花盆等
//unordered_set<int> Forbid_one = { 3,22,23,36,46,10,42 }; //第一格禁种植物
//unordered_set<int> Forbid_two = { 10 };//第二格禁种植物
extern bool Animatedflag;

void RandInit(vector<int> allow, vector<int> gift) {
    memset(plantIfAllow, true, sizeof(bool) * 48);
    memset(plantIfGift, false, sizeof(bool) * 48);
    for (int i = 0; i < allow.size(); i++) plantIfAllow[allow[i]] = false;
    for (int i = 0; i < gift.size(); i++) plantIfGift[gift[i]] = true;
}


inline int JudgeIfOk(int** form,int num, int r, int l) {
    if (!plantIfAllow[num]) return 0;
    else if (plantIfGift[num]) return 1;
    //else if (l == 0 && Forbid_one.find(num) != Forbid_one.end()) return 0;
    //else if (l == 1 && Forbid_two.find(num) != Forbid_two.end()) return 0;
    else if (num == 22) {//判断火炬的逻辑，火炬前是否有豌豆射手、双发、裂荚或机枪射手
        for (int i = 0; i < l; i++) if (form[r][i] == 0 || form[r][i] == 7 || form[r][i] == 40 || form[r][i] == 28) return 2;
        return 0;
    }
    else return 2;
}

inline int JudgeIfOk(int num, int r, int l) {
    if (!plantIfAllow[num]) return 0;
    else if (plantIfGift[num]) return 1;
    //else if (l == 0 && Forbid_one.find(num) != Forbid_one.end()) return 0;
    //else if (l == 1 && Forbid_two.find(num) != Forbid_two.end()) return 0;
    else return 2;
}

int RandForm(bool** noneedposition) {
    int** randform=new int*[MaxRow];
    for (int i = 0; i < MaxRow; i++) {
        randform[i] = new int[MaxCol];
    }
    int count=0;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 47*100);
    for (int i = 0; i < MaxRow; i++)
        for (int j = 0; j < MaxCol; j++) {
            if(noneedposition[i][j]) continue;
            else{
                int temp;
                while (true) {
                    temp = dis(gen)%48;
                    switch (JudgeIfOk(randform, temp, i , j )) {
                    case 0:continue;
                    case 1:
                        if(Animatedflag) AnimatedWhenPlant(i,j);
                        PlacePlant(i, j, temp);count++; continue;
                    case 2:break;
                    }
                    if(Animatedflag) AnimatedWhenPlant(i,j);
                    PlacePlant(i, j, temp);
                    randform[i][j] = temp;
                    count++;
                    break;
                }
            }
        }
    return count;
}

void PlacePlant(int row, int col, int type)
{
    CodeStruct* newPlant = Init();
    PushDword(newPlant, -1);
    PushDword(newPlant, type);
    MovReg(newPlant, Reg::EAX, row);
    PushDword(newPlant, col);
    MovRegDwordptr(newPlant, Reg::EBP, lawn);
    MovRegDwordptrOff(newPlant, Reg::EBP, board);
    PushReg(newPlant, Reg::EBP);
    Call(newPlant, call_place_plant);
    Ret(newPlant);
    CodeInject(newPlant);
}

void CustomForm()
{
    int** formation = new int* [MaxRow];
    for (int i = 0; i < MaxRow; i++) {
        formation[i] = new int[MaxCol];
    }
    for (int i = 0; i < MaxRow; i++)
        for (int j = 0; j < MaxCol; j++)
            cin >> formation[i][j];
    for (int i = 0; i < MaxRow; i++)
        for (int j = 0; j < MaxCol; j++) {
            if (formation[i][j] < 48 && formation[i][j] >= 0)
                PlacePlant(i, j, formation[i][j]);
        }
}

inline int RandSingle(int row,int col)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 47);
    int temp;
    //while (true) {
        temp = dis(gen);
        //switch (JudgeIfOk(temp, row, col)) {
       // case 0:continue;
       // case 1:break;
       // case 2:break;
       // }
        PlacePlant(row, col, temp);
       // break;
   // }
    return temp;
}


void ClearAllPlants()
{
    unsigned int Plant_single_size=plant_single_size;
    auto Plant_count_max = ReadMemory<uint32_t>({lawn, board, plant_count_max});
    auto Plant_offset = ReadMemory<uint32_t>({lawn, board, plant_offset});
    //CodeStruct* clearplant = Init();
    WriteMemory<uint32_t>(0,{lawn, board,plant_curren_count});
    for (size_t i = 0 ; i <Plant_count_max; i++)
    {
        WriteMemory<uint32_t>(0,{Plant_offset+plant_blood+Plant_single_size * i});
        // auto Plant_blood= ReadMemory<bool>({Plant_offset + plant_blood + Plant_single_size * i});
       // if(Plant_blood==0)continue;
       // auto Plant_dead = ReadMemory<bool>({Plant_offset + plant_dead + Plant_single_size * i});
       // auto Plant_squished = ReadMemory<bool>({Plant_offset + plant_squished + Plant_single_size * i});
       // if (!Plant_dead && !Plant_squished)
       // {
            //uint32_t addr = Plant_offset + Plant_single_size * i;
           // PushDword(clearplant,addr);
          //  Call(clearplant,call_delete_plant);
       // }
   }
    WriteMemory<uint32_t>(0,{lawn, board,plant_count_max});
    WriteMemory<uint32_t>(56417,{lawn, board,plant_last_number});
    WriteMemory<uint32_t>(0,{lawn, board,plant_next_plant_position});
   // Ret(clearplant);
    //CodeInject(clearplant);
}

void DeleteSinglePlant(int row,int col, int type)
{
    unsigned int Plant_single_size=plant_single_size;
    auto Plant_count_max = ReadMemory<uint32_t>({lawn, board, plant_count_max});
    uint32_t Plant_offset = ReadMemory<uint32_t>({lawn, board, plant_offset});
    CodeStruct* clearplant = Init();
    for (size_t i = Plant_count_max-1; i >=0; i--)
    {
        auto Plant_dead = ReadMemory<bool>({Plant_offset + plant_dead + Plant_single_size * i});
        if(Plant_dead) continue;
        auto Plant_row = ReadMemory<uint32_t>({Plant_offset + plant_row + Plant_single_size * i});
        if(Plant_row!=row) continue;
        auto Plant_col = ReadMemory<uint32_t>({Plant_offset + plant_col + Plant_single_size * i});
        if(Plant_col!=col)continue;
        auto Plant_type = ReadMemory<uint32_t>({Plant_offset + plant_type + Plant_single_size * i});
        if(Plant_type!=type)continue;
        uint32_t addr = Plant_offset + Plant_single_size *i;
        PushDword(clearplant,addr);
        Call(clearplant,call_delete_plant);
        Ret(clearplant);
        CodeInject(clearplant);
        return ;
    }
}

void DeleteGivenPlant(uint32_t Offset)
{
    unsigned int Plant_single_size=plant_single_size;
    //auto Plant_count_max = ReadMemory<uint32_t>({lawn, board, plant_count_max});
    uint32_t Plant_offset = ReadMemory<uint32_t>({lawn, board, plant_offset});
    CodeStruct* clearplant = Init();
    //auto Plant_dead = ReadMemory<bool>({Plant_offset + Offset*Plant_single_size+plant_dead});
    //if(Plant_dead) return;
    uint32_t addr = Plant_offset + Offset*Plant_single_size;
    PushDword(clearplant,addr);
    Call(clearplant,call_delete_plant);
    Ret(clearplant);
    CodeInject(clearplant);
    return ;
}

void DeleteGivenAddrPlant(uint32_t addr)
{
    CodeStruct* clearplant = Init();
    PushDword(clearplant,addr);
    Call(clearplant,call_delete_plant);
    Ret(clearplant);
    CodeInject(clearplant);
    return ;
}

void AnimatedWhenPlant(int row,int col)
{
    auto NextPlantOffset=ReadMemory<uint32_t>({lawn,board,plant_next_plant_position});
    auto currentplantcount=ReadMemory<uint32_t>({lawn,board,plant_curren_count});
    for(int i=0;i<3;i++)
    {
        WriteMemory<uint32_t>(666,{lawn,board,plant_next_plant_position});
        RandSingle(row,col);
        chrono::milliseconds sleepDuration(50);
        this_thread::sleep_for(sleepDuration);
        DeleteGivenPlant(666);
    }
    WriteMemory<uint32_t>(NextPlantOffset,{lawn,board,plant_next_plant_position});
    WriteMemory<uint32_t>(currentplantcount,{lawn,board,plant_curren_count});
    chrono::milliseconds sleepDuration(50);
    this_thread::sleep_for(sleepDuration);
}
