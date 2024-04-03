#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// Абстрактный класс аппаратного устройства
class AbstractDevice abstract {
protected:
    string producer;

public:
    string GetProducer() {
        return this->producer;
    }
    void SetProducer(string producer) {
        this->producer = producer;
    }
    // Метод создания клона объекта
    virtual AbstractDevice* Clone() abstract;
};

class Box : public AbstractDevice {
    string color;
public:
    string GetColor() {
        return this->color;
    }
    void SetColor(string color) {
        this->color = color;
    }
    AbstractDevice* Clone() override {
        Box* box = new Box;
        *box = *this;
        return box;
    }
};

class Memory : public AbstractDevice {
    int volume;
    string type;
public:
    string GetType() {
        return this->type;
    }
    void SetType(string type) {
        this->type = type;
    }
    int GetVolume() {
        return this->volume;
    }
    void SetVolume(int volume) {
        this->volume = volume;
    }
    AbstractDevice* Clone() override {
        Memory* memory = new Memory;
        *memory = *this;
        return memory;
    }
};

class Hdd : public AbstractDevice {
    int volume;
    string type;
public:
    string GetType() {
        return this->type;
    }
    void SetType(string type) {
        this->type = type;
    }
    int GetVolume() {
        return this->volume;
    }
    void SetVolume(int volume) {
        this->volume = volume;
    }
    AbstractDevice* Clone() override {
        Hdd* hdd = new Hdd;
        *hdd = *this;
        return hdd;
    }
};

class Processor : public AbstractDevice {
    int corecount;
    double frequency;
public:
    double GetFrequency() {
        return this->frequency;
    }
    void SetFrequency(double frequency) {
        this->frequency = frequency;
    }
    int GetCoreCount() {
        return this->corecount;
    }
    void SetCoreCount(int corecount) {
        this->corecount = corecount;
    }
    AbstractDevice* Clone() override {
        Processor* processor = new Processor;
        *processor = *this;
        return processor;
    }
};

class VideoCard : public AbstractDevice {
    int volume;
public:
    int GetVolume() {
        return this->volume;
    }
    void SetVolume(int volume) {
        this->volume = volume;
    }
    AbstractDevice* Clone() override {
        VideoCard* videocard = new VideoCard;
        *videocard = *this;
        return videocard;
    }
};

class Mainboard : public AbstractDevice {
    double busfrequency;
    VideoCard* videocard;
public:
    double GetBusFrequency() {
        return this->busfrequency;
    }
    void SetBusFrequency(double busfrequency) {
        this->busfrequency = busfrequency;
    }
    VideoCard* GetVideoCard() {
        return this->videocard;
    }
    void SetVideoCard(VideoCard* videocard) {
        this->videocard = videocard;
    }
    AbstractDevice* Clone() override {
        Mainboard* newObj = new Mainboard;
        *newObj = *this;
        newObj->videocard = this->videocard != nullptr ? (VideoCard*)this->videocard->Clone() : nullptr;
        return newObj;
    }
};

class Cam : public AbstractDevice {
    int resolution;
public:
    int GetResolution() {
        return this->resolution;
    }
    void SetResolution(int resolution) {
        this->resolution = resolution;
    }
    AbstractDevice* Clone() override {
        Cam* cam = new Cam;
        *cam = *this;
        return cam;
    }
};

class WirelessMouse : public AbstractDevice {
    string brand;
public:
    string GetBrand() {
        return this->brand;
    }
    void SetBrand(string brand) {
        this->brand = brand;
    }
    AbstractDevice* Clone() override {
        WirelessMouse* mouse = new WirelessMouse;
        *mouse = *this;
        return mouse;
    }
};

class Prototype abstract {
public:
    virtual Prototype* Clone() abstract;
};

class PersonalComputer : public Prototype {
    Box* box;
    Mainboard* mainboard;
    Processor* processor;
    VideoCard* videocard;
    vector<Memory*> memories;
    vector<Hdd*> hdd;
public:
    Box* GetBox() {
        return this->box;
    }
    void SetBox(Box* box) {
        this->box = box;
    }
    Processor* GetProcessor() {
        return this->processor;
    }
    void SetProcessor(Processor* processor) {
        this->processor = processor;
    }
    Mainboard* GetMainboard() {
        return this->mainboard;
    }
    void SetMainboard(Mainboard* mainboard) {
        this->mainboard = mainboard;
    }
    VideoCard* GetVideoCard() {
        return this->videocard;
    }
    void SetVideoCard(VideoCard* videocard) {
        this->videocard = videocard;
    }
    vector<Memory*>& GetMemories() {
        return memories;
    }
    void AddMemory(Memory* m) {
        memories.push_back(m);
    }
    vector<Hdd*>& GetHdd() {
        return hdd;
    }
    void AddHdd(Hdd* hdd) {
        this->hdd.push_back(hdd);
    }
    Prototype* Clone() override {
        PersonalComputer* pc = new PersonalComputer;
        pc->box = this->box != nullptr ? (Box*)this->box->Clone() : nullptr;
        pc->mainboard = this->mainboard != nullptr ? (Mainboard*)this->mainboard->Clone() : nullptr;
        pc->processor = this->processor != nullptr ? (Processor*)this->processor->Clone() : nullptr;
        pc->videocard = this->videocard != nullptr ? (VideoCard*)this->videocard->Clone() : nullptr;
        for (Memory* m : this->memories) {
            if (m != nullptr) {
                pc->AddMemory((Memory*)m->Clone());
            }
        }
        for (Hdd* h : this->hdd) {
            if (h != nullptr) {
                pc->AddHdd((Hdd*)h->Clone());
            }
        }
        return pc;
    }
};

class MobilePhone : public Prototype {
    Processor* processor;
    Memory* memory;
    Hdd* hdd;
    Cam* cam;
public:
    Processor* GetProcessor() {
        return this->processor;
    }
    void SetProcessor(Processor* processor) {
        this->processor = processor;
    }
    Memory* GetMemory() {
        return this->memory;
    }
    void SetMemory(Memory* memory) {
        this->memory = memory;
    }
    Hdd* GetHdd() {
        return this->hdd;
    }
    void SetHdd(Hdd* hdd) {
        this->hdd = hdd;
    }
    Cam* GetCam() {
        return this->cam;
    }
    void SetCam(Cam* cam) {
        this->cam = cam;
    }
    Prototype* Clone() override {
        MobilePhone* phone = new MobilePhone;
        phone->processor = this->processor != nullptr ? (Processor*)this->processor->Clone() : nullptr;
        phone->memory = this->memory != nullptr ? (Memory*)this->memory->Clone() : nullptr;
        phone->hdd = this->hdd != nullptr ? (Hdd*)this->hdd->Clone() : nullptr;
        phone->cam = this->cam != nullptr ? (Cam*)this->cam->Clone() : nullptr;
        return phone;
    }
};

class Laptop : public Prototype {
    Processor* processor;
    VideoCard* videocard;
    Memory* memory;
    Hdd* hdd;
    Cam* cam;
    WirelessMouse* mouse;
public:
    Processor* GetProcessor() {
        return this->processor;
    }
    void SetProcessor(Processor* processor) {
        this->processor = processor;
    }
    VideoCard* GetVideoCard() {
        return this->videocard;
    }
    void SetVideoCard(VideoCard* videocard) {
        this->videocard = videocard;
    }
    Memory* GetMemory() {
        return this->memory;
    }
    void SetMemory(Memory* memory) {
        this->memory = memory;
    }
    Hdd* GetHdd() {
        return this->hdd;
    }
    void SetHdd(Hdd* hdd) {
        this->hdd = hdd;
    }
    Cam* GetCam() {
        return this->cam;
    }
    void SetCam(Cam* cam) {
        this->cam = cam;
    }
    WirelessMouse* GetMouse() {
        return this->mouse;
    }
    void SetMouse(WirelessMouse* mouse) {
        this->mouse = mouse;
    }
    Prototype* Clone() override {
        Laptop* laptop = new Laptop;
        laptop->processor = this->processor != nullptr ? (Processor*)this->processor->Clone() : nullptr;
        laptop->videocard = this->videocard != nullptr ? (VideoCard*)this->videocard->Clone() : nullptr;
        laptop->memory = this->memory != nullptr ? (Memory*)this->memory->Clone() : nullptr;
        laptop->hdd = this->hdd != nullptr ? (Hdd*)this->hdd->Clone() : nullptr;
        laptop->cam = this->cam != nullptr ? (Cam*)this->cam->Clone() : nullptr;
        laptop->mouse = this->mouse != nullptr ? (WirelessMouse*)this->mouse->Clone() : nullptr;
        return laptop;
    }
};

// Класс палитры типичных конфигураций
class PcPrototypes {
    // Словарь, в котором хранятся прототипы конфигураций
    map<string, Prototype*> pcprototypes;
public:
    PcPrototypes() {
        // инициализация палитры прототипами конфигураций
        InitializePcPrototypes();
    }
    // Доступ к прототипу конфигурации по его имени
    Prototype* operator[](string key) {
        return  pcprototypes[key];
    }
    void InitializePcPrototypes() {
        pcprototypes["Home"] = CreateHomeConfig();
        pcprototypes["Office"] = CreateOfficeConfig();
        pcprototypes["Game"] = CreateGamerConfig();
        pcprototypes["MobilePhone"] = CreateMobilePhoneConfig();
        pcprototypes["Laptop"] = CreateLaptopConfig();
    }

    PersonalComputer* CreateHomeConfig() {
        PersonalComputer* config = new PersonalComputer();
        Box* box = new Box();
        box->SetColor("Silver");
        config->SetBox(box);

        Mainboard* mainboard = new Mainboard();
        mainboard->SetProducer("ATI");
        mainboard->SetBusFrequency(800);
        mainboard->SetVideoCard(nullptr);
        config->SetMainboard(mainboard);

        Processor* processor = new Processor();
        processor->SetProducer("Intel");
        processor->SetCoreCount(2);
        processor->SetFrequency(3);
        config->SetProcessor(processor);

        VideoCard* videocard = new VideoCard();
        videocard->SetProducer("ATI");
        videocard->SetVolume(1024);
        config->SetVideoCard(videocard);

        Hdd* hdd = new Hdd();
        hdd->SetProducer("Samsung");
        hdd->SetType("SATA");
        hdd->SetVolume(500);
        config->AddHdd(hdd);

        Memory* memory = new Memory();
        memory->SetType("DDR2");
        memory->SetVolume(2);
        config->AddMemory(memory);
        return config;
    }

    PersonalComputer* CreateOfficeConfig() {
        PersonalComputer* config = new PersonalComputer();
        Box* box = new Box();
        box->SetColor("White");
        config->SetBox(box);

        Mainboard* mainboard = new Mainboard();
        mainboard->SetProducer("Albatron");
        mainboard->SetBusFrequency(800);

        VideoCard* videocard = new VideoCard();
        videocard->SetProducer("nVidia");
        videocard->SetVolume(1024);
        mainboard->SetVideoCard(videocard);
        config->SetMainboard(mainboard);

        Processor* processor = new Processor();
        processor->SetProducer("AMD");
        processor->SetCoreCount(1);
        processor->SetFrequency(1.8);
        config->SetProcessor(processor);

        Hdd* hdd = new Hdd();
        hdd->SetProducer("LG");
        hdd->SetType("SATA");
        hdd->SetVolume(160);
        config->AddHdd(hdd);

        Memory* memory = new Memory();
        memory->SetType("DDR2");
        memory->SetVolume(1);
        config->AddMemory(memory);

        config->SetVideoCard(nullptr);
        return config;
    }

    PersonalComputer* CreateGamerConfig() {
        PersonalComputer* config = new PersonalComputer();

        Box* box = new Box();
        box->SetColor("Black");
        config->SetBox(box);

        Mainboard* mainboard = new Mainboard();
        mainboard->SetProducer("Asus");
        mainboard->SetBusFrequency(800);
        mainboard->SetVideoCard(nullptr);
        config->SetMainboard(mainboard);

        Processor* processor = new Processor();
        processor->SetProducer("Intel");
        processor->SetCoreCount(4);
        processor->SetFrequency(4);
        config->SetProcessor(processor);

        VideoCard* videocard = new VideoCard();
        videocard->SetProducer("nVidia");
        videocard->SetVolume(1024);
        config->SetVideoCard(videocard);

        Hdd* hdd = new Hdd();
        hdd->SetProducer("WD");
        hdd->SetType("SATA2");
        hdd->SetVolume(1024);
        config->AddHdd(hdd);

        Memory* memory = new Memory();
        memory->SetType("DDR2");
        memory->SetVolume(4);
        config->AddMemory(memory);
        return config;
    }

    MobilePhone* CreateMobilePhoneConfig() {
        MobilePhone* config = new MobilePhone();

        Processor* processor = new Processor();
        processor->SetProducer("Apple iPhone");
        processor->SetCoreCount(6);
        processor->SetFrequency(3.5); // Example values
        config->SetProcessor(processor);

        Memory* memory = new Memory();
        memory->SetType("LPDDR5");
        memory->SetVolume(8);
        config->SetMemory(memory);

        Hdd* hdd = new Hdd();
        hdd->SetProducer("Apple");
        hdd->SetType("SSD");
        hdd->SetVolume(256); // Example value
        config->SetHdd(hdd);

        Cam* cam = new Cam();
        cam->SetProducer("Sony");
        cam->SetResolution(48); // Example resolution
        config->SetCam(cam);
        return config;
    }


    Laptop* CreateLaptopConfig() {
        Laptop* config = new Laptop();

        Processor* processor = new Processor();
        processor->SetProducer("AMD RYZEN 9 7940HS");
        processor->SetCoreCount(16);
        processor->SetFrequency(4.2); // Example values
        config->SetProcessor(processor);

        VideoCard* videocard = new VideoCard();
        videocard->SetProducer("Nvidia RTX 4050");
        videocard->SetVolume(4096); // Example value
        config->SetVideoCard(videocard);

        Memory* memory = new Memory();
        memory->SetType("LPDDR5");
        memory->SetVolume(32);
        config->SetMemory(memory);

        Hdd* hdd = new Hdd();
        hdd->SetProducer("WD");
        hdd->SetType("SSD");
        hdd->SetVolume(2048); // Example value
        config->SetHdd(hdd);

        Cam* cam = new Cam();
        cam->SetProducer("Sony");
        cam->SetResolution(8); // Example resolution
        config->SetCam(cam);

        WirelessMouse* mouse = new WirelessMouse();
        mouse->SetBrand("Logitech");
        config->SetMouse(mouse);
        return config;
    }

};

void PrintPc(PersonalComputer* pc) {
    cout << "PC configuration: " << endl;
    cout << "Box: " << pc->GetBox()->GetColor() << endl;
    cout << "Mainboard: " << pc->GetMainboard()->GetProducer() << pc->GetMainboard()->GetBusFrequency() << " MHz" << endl;
    if (pc->GetMainboard()->GetVideoCard() != nullptr) {
        cout << "Integrated VideoCard: " << pc->GetMainboard()->GetVideoCard()->GetProducer()
            << pc->GetMainboard()->GetVideoCard()->GetVolume() << " Mb" << endl;
    }
    cout << "Processor: " << pc->GetProcessor()->GetProducer()
        << pc->GetProcessor()->GetFrequency() << " GHz "
        << pc->GetProcessor()->GetCoreCount() << " core" << endl;
    cout << "Memories: ";
    for (Memory* m : pc->GetMemories()) {
        cout << m->GetType() << "  " << m->GetVolume() << " Gb\n";
    }
    cout << "Hdds: ";
    for (Hdd* h : pc->GetHdd()) {
        cout << h->GetProducer() << "  " << h->GetType() << "  " << h->GetVolume() << " Gb\n";
    }
    if (pc->GetVideoCard() != nullptr) {
        cout << "VideoCard: ";
        cout << pc->GetVideoCard()->GetProducer() << "  " << pc->GetVideoCard()->GetVolume() << " Mb\n";
    }
}

void PrintMobilePhone(MobilePhone* phone) {
    cout << "Mobile Phone configuration: " << endl;
    if (phone->GetProcessor() != nullptr) {
        cout << "Processor: " << phone->GetProcessor()->GetProducer() << " " << phone->GetProcessor()->GetFrequency() << " GHz " << phone->GetProcessor()->GetCoreCount() << " cores" << endl;
    }
    if (phone->GetMemory() != nullptr) {
        cout << "Memory: " << phone->GetMemory()->GetType() << " " << phone->GetMemory()->GetVolume() << " GB" << endl;
    }
    if (phone->GetHdd() != nullptr) {
        cout << "HDD: " << phone->GetHdd()->GetProducer() << " " << phone->GetHdd()->GetType() << " " << phone->GetHdd()->GetVolume() << " GB" << endl;
    }
    if (phone->GetCam() != nullptr) {
        cout << "Cam: " << phone->GetCam()->GetProducer() << " " << phone->GetCam()->GetResolution() << " MP" << endl;
    }
}

void PrintLaptop(Laptop* laptop) {
    cout << "Laptop configuration: " << endl;
    if (laptop->GetProcessor() != nullptr) {
        cout << "Processor: " << laptop->GetProcessor()->GetProducer() << " " << laptop->GetProcessor()->GetFrequency() << " GHz " << laptop->GetProcessor()->GetCoreCount() << " cores" << endl;
    }
    if (laptop->GetVideoCard() != nullptr) {
        cout << "Video Card: " << laptop->GetVideoCard()->GetProducer() << " " << laptop->GetVideoCard()->GetVolume() << " Mhz" << endl;
    }
    if (laptop->GetMemory() != nullptr) {
        cout << "Memory: " << laptop->GetMemory()->GetType() << " " << laptop->GetMemory()->GetVolume() << " GB" << endl;
    }
    if (laptop->GetHdd() != nullptr) {
        cout << "HDD: " << laptop->GetHdd()->GetProducer() << " " << laptop->GetHdd()->GetType() << " " << laptop->GetHdd()->GetVolume() << " GB" << endl;
    }
    if (laptop->GetCam() != nullptr) {
        cout << "Cam: " << laptop->GetCam()->GetProducer() << " " << laptop->GetCam()->GetResolution() << " MP" << endl;
    }
    if (laptop->GetMouse() != nullptr) {
        cout << "Wireless Mouse: " << laptop->GetMouse()->GetBrand() << endl;
    }
}

int main() {
    // Создаем палитру прототипов
    PcPrototypes* prototypes = new PcPrototypes();

    // Создаем конфигурации ПК
    PersonalComputer* homePc = (PersonalComputer*)prototypes->CreateHomeConfig()->Clone();
    PersonalComputer* officePc = (PersonalComputer*)prototypes->CreateOfficeConfig()->Clone();
    PersonalComputer* gamePc = (PersonalComputer*)prototypes->CreateGamerConfig()->Clone();

    // Печать конфигураций ПК
    cout << "------- Home PC Configuration -------" << endl;
    PrintPc(homePc);
    cout << endl;

    cout << "------- Office PC Configuration -------" << endl;
    PrintPc(officePc);
    cout << endl;

    cout << "------- Gamer PC Configuration -------" << endl;
    PrintPc(gamePc);
    cout << endl;

    // Создаем конфигурацию мобильного телефона
    MobilePhone* mobilePhone = (MobilePhone*)prototypes->CreateMobilePhoneConfig()->Clone();

    // Печать конфигурации мобильного телефона
    cout << "------- Mobile Phone Configuration -------" << endl;
    PrintMobilePhone(mobilePhone);
    cout << endl;

    // Создаем конфигурацию ноутбука
    Laptop* laptop = (Laptop*)prototypes->CreateLaptopConfig()->Clone();

    // Печать конфигурации ноутбука
    cout << "------- Laptop Configuration -------" << endl;
    PrintLaptop(laptop);
    cout << endl;

    // Освобождение памяти
    delete homePc;
    delete officePc;
    delete gamePc;
    delete mobilePhone;
    delete laptop;
    delete prototypes;

    return 0;
}
