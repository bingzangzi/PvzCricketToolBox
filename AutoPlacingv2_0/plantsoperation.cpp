#include "plantsoperation.h"
bool* global_forbid_plant;
vector<bool> global_gift_plant;
vector<bool*> row_forbid_plant;
vector<bool*> col_forbid_plant;
vector<unordered_set<int>> single_forbid_plant(60);
vector<unsigned char> plantbulletaddr_1={0x50,0x8b,0x44,0x24,0x10};
vector<unsigned char> zombieattackedaddr={0x51,0x8b,0x4e,0x28,0x83,0xf9,0x10};
vector<unsigned char> firejudgeaddr={0x8b,0x54,0x24,0x3c,0x8b,0xc8};
LPVOID plantbulletaddr_1_injectaddr;
LPVOID plantbulletaddr_hypno_injectaddr;
LPVOID plantbulletaddr_firepea_injectaddr;
extern HACK<uint8_t, 1> block_main_loop;
void ClearAllPlants()
{
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 开始清空植物\n").arg(currentTime);
    }
    unsigned int Plant_single_size=plant_single_size;
    auto Plant_count_max = ReadMemory<uint32_t>({lawn, board, plant_count_max});
    auto Plant_offset = ReadMemory<uint32_t>({lawn, board, plant_offset});
    CodeStruct* clearplant = Init();
    WriteMemory<uint32_t>(0,{lawn, board,plant_curren_count});
    for (size_t i = 0 ; i <Plant_count_max; i++)
    {
        //WriteMemory<uint32_t>(0,{Plant_offset+plant_blood+Plant_single_size * i});
        auto Plant_blood= ReadMemory<bool>({Plant_offset + plant_blood + Plant_single_size * i});
        if(Plant_blood==0)continue;
        auto Plant_dead = ReadMemory<bool>({Plant_offset + plant_dead + Plant_single_size * i});
        auto Plant_squished = ReadMemory<bool>({Plant_offset + plant_squished + Plant_single_size * i});
        if (!Plant_dead && !Plant_squished)
        {
            uint32_t addr = Plant_offset + Plant_single_size * i;
            PushDword(clearplant,addr);
            Call(clearplant,call_delete_plant);
        }
    }
    Ret(clearplant);
    if(CheckBoardOn())CodeInject(pvzHand,clearplant);
    else return;
    WriteMemory<uint32_t>(0,{lawn, board,plant_count_max});
    //WriteMemory<uint32_t>(56417,{lawn, board,plant_last_number});
    WriteMemory<uint32_t>(0,{lawn, board,plant_next_plant_position});
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 结束清空植物\n").arg(currentTime);
    }
}

bool JudgeifForbid(int type,int row,int col)
{
    if(global_forbid_plant[type]) return true;
    if(row==-1&&col==-1) return false;
    if(row_forbid_plant.size()!=0)if(row_forbid_plant[row][type]) return true;
    if(col_forbid_plant.size()!=0)if(col_forbid_plant[col][type]) return true;
    if(single_forbid_plant[row*10+col].find(type)!=single_forbid_plant[row*10+col].end()) return true;
    return false;
}

bool RandPlantplace(vector<bool> plantposition,bool isforbid,int typesize,int maxcol)
{
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 开始随机种植\n").arg(currentTime);
        out.flush();
    }
    CodeStruct* newPlant=Init();
    int temp;
    bool flag=false;
    for(int i=0;i<plantposition.size();i++){
        if(!plantposition[i]) continue;
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(0, typesize-1);
        temp=dis(gen);
        if(isforbid) while(JudgeifForbid(temp,i/maxcol,i%maxcol)) temp=dis(gen);
        while(global_gift_plant[temp]){
            if(temp!=48){
                PushDword(newPlant, -1);
                PushDword(newPlant, temp);
            }
            else{
                temp=dis(gen);
                if(isforbid) while(JudgeifForbid(temp,i/maxcol,i%maxcol)&&temp==48) temp=dis(gen);
                PushDword(newPlant, temp);
                PushDword(newPlant, 48);
            }
            MovReg(newPlant, Reg::EAX, i/maxcol);
            PushDword(newPlant, i%maxcol);
            MovRegDwordptr(newPlant, Reg::EBP, lawn);
            MovRegDwordptrOff(newPlant, Reg::EBP, board);
            PushReg(newPlant, Reg::EBP);
            Call(newPlant, call_place_plant);
            temp=dis(gen);
            if(isforbid) while(JudgeifForbid(temp,i/maxcol,i%maxcol)) temp=dis(gen);
        }
        if(temp!=48){
            PushDword(newPlant, -1);
            PushDword(newPlant, temp);
        }
        else{
            temp=dis(gen);
            if(isforbid) while(JudgeifForbid(temp,i/maxcol,i%maxcol)&&temp==48) temp=dis(gen);
            PushDword(newPlant, temp);
            PushDword(newPlant, 48);
        }
        MovReg(newPlant, Reg::EAX, i/maxcol);
        PushDword(newPlant, i%maxcol);
        MovRegDwordptr(newPlant, Reg::EBP, lawn);
        MovRegDwordptrOff(newPlant, Reg::EBP, board);
        PushReg(newPlant, Reg::EBP);
        Call(newPlant, call_place_plant);
        flag=true;

    }
    if(!flag){
        delete newPlant;
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 随机种植终止，因为没有植物种植\n").arg(currentTime);
            out.flush();
        }
        return false;
    }
    Ret(newPlant);
    if(CheckBoardOn())CodeInject(pvzHand,newPlant);
    else return false;
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 随机种植完成\n").arg(currentTime);
        out.flush();
    }
    return true;
}

void SinglePlantPlace(int type,int row,int col)
{
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 开始单个植物种植\n").arg(currentTime);
        out.flush();
    }
    CodeStruct* newPlant=Init();
    if(type!=48){
        PushDword(newPlant, -1);
        PushDword(newPlant, type);
    }
    else{
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(0, global_gift_plant.size());
        int temp=dis(gen);
        while(temp==48) temp=dis(gen);
        PushDword(newPlant, temp);
        PushDword(newPlant, 48);
    }
    MovReg(newPlant, Reg::EAX, row);
    PushDword(newPlant, col);
    MovRegDwordptr(newPlant, Reg::EBP, lawn);
    MovRegDwordptrOff(newPlant, Reg::EBP, board);
    PushReg(newPlant, Reg::EBP);
    Call(newPlant, call_place_plant);
    Ret(newPlant);
    if(CheckBoardOn())CodeInject(pvzHand,newPlant);
    else return;
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 结束单个植物种植\n").arg(currentTime);
        out.flush();
    }
}

vector<vector<int>> StringCheck(const QString& formtext,bool blood,bool interval,int plantbooksize,int maxrow)
{
    vector<vector<int>> plantinfo;
    QRegularExpression re("\\d+");
    vector<vector<int>> nullvector;
    QRegularExpressionMatchIterator i = re.globalMatch(formtext);

    QString result;
    vector<int> newinfo;
    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        QString numberStr = match.captured();
        int number = numberStr.toInt();
        newinfo.push_back(number);
        if(newinfo.size() == 1) if(newinfo[0]>=plantbooksize&&newinfo[0]<0)  return nullvector;
        if(newinfo.size() == 2) if(newinfo[1]>maxrow&&newinfo[1]<=0)    return nullvector;
        if(newinfo.size() == 3) if(newinfo[2]>10&&newinfo[2]<=0)    return nullvector;
        if ((!blood&&!interval&&newinfo.size() == 3) || (blood &&!interval &&newinfo.size() == 4) || (!blood &&interval && newinfo.size() == 4)) {
            plantinfo.push_back(newinfo);
            newinfo.clear();
        }
        if(newinfo.size() == 4) if(newinfo[3]<0)    return nullvector;
        if (blood &&interval &&newinfo.size() == 5) {
            if(newinfo.size() == 5) if(newinfo[4]<0)    return nullvector;
            plantinfo.push_back(newinfo);
            newinfo.clear();
        }
    }
    return plantinfo;
}

QString FormToString(bool blood,bool interval)
{
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 正在阵型转字符串\n").arg(currentTime);
        out.flush();
    }
    QString str;
    uint32_t offset=ReadMemory<uint32_t>({lawn,board,plant_offset});
    uint32_t maxcount=ReadMemory<uint32_t>({lawn,board,plant_count_max});
    for(size_t i=0;i<maxcount;i++){
        if(!CheckBoardOn()){
            if(out.device()){
                QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
                out<<QString("[%1] 未检测到关卡，退出阵型转字符串\n").arg(currentTime);
                out.flush();
            }
            return QString("");
        }
        bool isdead=ReadMemory<bool>({offset+plant_single_size*i+plant_dead});
        if(isdead) continue;
        bool issquished=ReadMemory<bool>({offset+plant_single_size*i+plant_squished});
        if(issquished) continue;
        uint32_t plantblood=ReadMemory<uint32_t>({offset+plant_single_size*i+plant_blood});
        if(plantblood==0) continue;
        uint32_t type=ReadMemory<uint32_t>({offset+plant_single_size*i+plant_type});
        uint32_t row=ReadMemory<uint32_t>({offset+plant_single_size*i+plant_row});
        uint32_t col=ReadMemory<uint32_t>({offset+plant_single_size*i+plant_col});
        uint32_t plantinterval=ReadMemory<uint32_t>({offset+plant_single_size*i+plant_attack_interval});
        str+=QString("%1 %2 %3").arg(type).arg(row+1).arg(col+1);
        if(blood)str+=QString(" %1").arg(plantblood);
        if(interval)str+=QString(" %1").arg(plantinterval);
        str+=QString(";\n");
    }
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 结束阵型转字符串\n").arg(currentTime);
        out.flush();
    }
    return str;
}

void CustomPlantAffectOnGame(vector<PlantEffectStruct>plant_effect_inlist)
{
    WriteMemory(block_main_loop.hack_value,{block_main_loop.mem_addr});
    Sleep(GetFrameDuration());

    if(plantbulletaddr_1_injectaddr!=NULL){
        VirtualFreeEx(pvzHand, plantbulletaddr_1_injectaddr, 0, MEM_RELEASE);
    }
    if(plantbulletaddr_hypno_injectaddr!=NULL){
        VirtualFreeEx(pvzHand, plantbulletaddr_hypno_injectaddr, 0, MEM_RELEASE);
    }
    if(plantbulletaddr_firepea_injectaddr!=NULL){
        VirtualFreeEx(pvzHand, plantbulletaddr_firepea_injectaddr, 0, MEM_RELEASE);
    }
    for(size_t i=0;i<plantbulletaddr_1.size();i++){
        WriteMemory<uint8_t>(plantbulletaddr_1[i],{0x40d63d+i});
    }
    for(size_t i=0;i<zombieattackedaddr.size();i++){
        WriteMemory<uint8_t>(zombieattackedaddr[i],{0x5317c0+i});
    }
    for(size_t i=0;i<firejudgeaddr.size();i++){
        WriteMemory<uint8_t>(firejudgeaddr[i],{0x4672b5+i});
    }

    SIZE_T bytesWritten;
    LPVOID remoteBuffer = VirtualAllocEx(pvzHand, NULL, 4096, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    plantbulletaddr_hypno_injectaddr = VirtualAllocEx(pvzHand, NULL, 4096, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    if (remoteBuffer == NULL||plantbulletaddr_hypno_injectaddr==NULL) {
        return ;
    }

    plantbulletaddr_1_injectaddr=remoteBuffer;
    uint32_t addr=reinterpret_cast<uintptr_t>(remoteBuffer);
    uint32_t hypnoaddr=reinterpret_cast<uintptr_t>(plantbulletaddr_hypno_injectaddr);

    plantbulletaddr_firepea_injectaddr=VirtualAllocEx(pvzHand, NULL, 1024, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    if (plantbulletaddr_firepea_injectaddr == NULL) {
        return ;
    }
    uint32_t firepeadaddr=reinterpret_cast<uintptr_t>(plantbulletaddr_firepea_injectaddr);
    CodeStruct* firecode=Init();
    int off_fire=firepeadaddr-4-0x004672b5;
    AddByte(firecode,0x60);

    int off=addr-4-0x40d63d;
    int off_hypo=hypnoaddr-4-0x5317c0;

    CodeStruct* newcode=Init();
    CodeStruct* hypnocode=Init();

    AddByte(hypnocode,0x60);
    for(auto list=plant_effect_inlist.begin();list!=plant_effect_inlist.end();list++){
        if(list->modifytype==0){
            AddList(newcode,{0x83,0x7d,0x24});
            AddByte(newcode,list->planttype);
            AddList(newcode,{0x0f,0x85});
            AddDword(newcode,0x5);
            AddByte(newcode,0xb8);
            AddDword(newcode,list->value_first[0]);
            if(list->value_first[0]==6){
                uint8_t valuebyte=list->planttype;
                AddList(firecode,{0x83,0x7d,0x24,valuebyte});
                AddList(firecode,{0x0f,0x85,0x14,0x00,0x00,0x00});
                AddList(firecode,{0x83,0x78,0x5c,0x06});
                AddList(firecode,{0x0f,0x85,0x0a,0x00,0x00,0x00});
                AddList(firecode,{0x8b,0xc8});
                AddList(firecode,{0x8b,0x45,0x28});
                AddList(firecode,{0xe8});
                int _calloff= (0x0046ecb0-4)-(firepeadaddr+firecode->length);
                AddDword(firecode,_calloff);
            }
        }
        else if(list->modifytype==1){
            AddList(newcode,{0x83,0x7d,0x24});
            AddByte(newcode,list->planttype);
            AddList(newcode,{0x0f,0x85});
            AddDword(newcode,0x17+(list->value_first.size()-1)*0x13);
            AddList(newcode,{0x0f,0xc7,0xf0});
            AddByte(newcode,0x51);
            AddByte(newcode,0x52);
            AddList(newcode,{0xb9,0x64,0x00,0x00,0x00});
            AddList(newcode,{0x31,0xd2});
            AddList(newcode,{0xf7,0xf1});
            AddList(newcode,{0x8b,0xc2});
            uint8_t count=0;
            for(size_t i=0;i<list->value_first.size()-1;i++){
                uint8_t valuebyte=list->value_second[i];
                count+=valuebyte;
                uint8_t targetvalue=count-1;
                AddList(newcode,{0x83,0xf8,targetvalue});
                AddList(newcode,{0x0f,0x83,0x0a,0x00,0x00,0x00});
                AddList(newcode,{0xb8});
                AddDword(newcode,list->value_first[i]);
                AddByte(newcode,0xe9);
                AddDword(newcode,(list->value_first.size()-2-i)*0x13+0x5);
                if(list->value_first[i]==6){
                    valuebyte=list->planttype;
                    AddList(firecode,{0x83,0x7d,0x24,valuebyte});
                    AddList(firecode,{0x0f,0x85,0x14,0x00,0x00,0x00});
                    AddList(firecode,{0x83,0x78,0x5c,0x06});
                    AddList(firecode,{0x0f,0x85,0x0a,0x00,0x00,0x00});
                    AddList(firecode,{0x8b,0xc8});
                    AddList(firecode,{0x8b,0x45,0x28});
                    AddList(firecode,{0xe8});
                    int _calloff= (0x0046ecb0-4)-(firepeadaddr+firecode->length);
                    AddDword(firecode,_calloff);
                }
            }
            AddByte(newcode,0xb8);
            AddDword(newcode,list->value_first.back());
            AddByte(newcode,0x5a);
            AddByte(newcode,0x59);
        }
        else if(list->modifytype==2){
            uint8_t valuebyte=list->value_first[0];
            AddList(hypnocode,{0x83,0xfb,valuebyte});
            AddList(hypnocode,{0x0f,0x85});
            AddDword(hypnocode,0x1e);
            AddList(hypnocode,{0x0f,0xc7,0xf0});
            AddList(hypnocode,{0xb9,0x64,0x00,0x00,0x00});
            AddList(hypnocode,{0x31,0xd2});
            AddList(hypnocode,{0xf7,0xf1});
            AddList(hypnocode,{0x8b,0xc2});
            valuebyte=list->value_second[0]-1;
            AddList(hypnocode,{0x83,0xf8,valuebyte});
            AddList(hypnocode,{0x0f,0x83});
            AddDword(hypnocode,0x07);
            AddList(hypnocode,{0xC6,0x86,0xB8,0x00,0x00,0x00,0x01});
        }
    }

    AddByte(newcode,0x50);
    AddList(newcode,{0x8b,0x44,0x24,0x10});
    AddList(newcode,{0xe9});
    int _off= (0x0040D642-4)-(addr+newcode->length);
    AddDword(newcode,_off);
    if(!WriteProcessMemory(pvzHand, remoteBuffer, newcode->code, newcode->length, &bytesWritten)){
        return;
    }

    AddByte(hypnocode,0x61);
    AddByte(hypnocode,0x51);
    AddList(hypnocode,{0x8b,0x4e,0x28});
    AddList(hypnocode,{0x83,0xf9,0x10});
    AddList(hypnocode,{0xe9});
    int _off_hypo= (0x5317c7-4)-(hypnoaddr+hypnocode->length);
    AddDword(hypnocode,_off_hypo);
    if(!WriteProcessMemory(pvzHand, plantbulletaddr_hypno_injectaddr, hypnocode->code, hypnocode->length, &bytesWritten)){
        return;
    }


    AddList(firecode,{0x61});
    AddList(firecode,{0x8b,0x54,0x24,0x3c});
    AddList(firecode,{0x8b,0xc8});
    AddList(firecode,{0xe9});
    int _off_fire= (0x4672bb-4)-(firepeadaddr+firecode->length);
    AddDword(firecode,_off_fire);
    if(!WriteProcessMemory(pvzHand, plantbulletaddr_firepea_injectaddr, firecode->code, firecode->length, &bytesWritten)){
        return;
    }


    CodeStruct* injectcode=Init();
    AddByte(injectcode,0xe9);
    AddDword(injectcode,off-1);
    for(size_t i=0;i<injectcode->length;i++){
        WriteMemory<uint8_t>(injectcode->code[i],{0x40d63d+i});
    }

    injectcode=Init();
    AddByte(injectcode,0xe9);
    AddDword(injectcode,off_hypo-1);
    AddList(injectcode,{0x66,0x90});
    for(size_t i=0;i<injectcode->length;i++){
        WriteMemory<uint8_t>(injectcode->code[i],{0x5317c0+i});
    }

    injectcode=Init();
    AddByte(injectcode,0xe9);
    AddDword(injectcode,off_fire-1);
    AddByte(injectcode,0x90);
    for(size_t i=0;i<injectcode->length;i++){
        WriteMemory<uint8_t>(injectcode->code[i],{0x004672b5+i});
    }

    WriteMemory(block_main_loop.reset_value,{block_main_loop.mem_addr});
}

void CustomPlantCancelAffectOnGame(){
    WriteMemory(block_main_loop.hack_value,{block_main_loop.mem_addr});
    Sleep(GetFrameDuration());
    if(plantbulletaddr_1_injectaddr!=NULL){
        VirtualFreeEx(pvzHand, plantbulletaddr_1_injectaddr, 0, MEM_RELEASE);
    }
    for(size_t i=0;i<plantbulletaddr_1.size();i++){
        WriteMemory<uint8_t>(plantbulletaddr_1[i],{0x40d63d+i});
    }
    for(size_t i=0;i<zombieattackedaddr.size();i++){
        WriteMemory<uint8_t>(zombieattackedaddr[i],{0x5317c0+i});
    }
    for(size_t i=0;i<firejudgeaddr.size();i++){
        WriteMemory<uint8_t>(firejudgeaddr[i],{0x4672b5+i});
    }
    WriteMemory(block_main_loop.reset_value,{block_main_loop.mem_addr});
}
