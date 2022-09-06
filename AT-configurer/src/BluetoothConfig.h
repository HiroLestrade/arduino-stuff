#include <Arduino.h>

class BluetoothConfig {
    private:
        String name;
        String pswd;
        String addr;
        int uart[3];
        int role;
        int cmode;
        int bind[3];
    public:
        BluetoothConfig(String name, String pswd, String addr);
        String getName(){return this->name;}
        String getPswd(){return this->pswd;}
        String getAddr(){return this->addr;}
        int* getUart(){return this->uart;}
        int getRole(){return this->role;}
        int getCmode(){return this->cmode;}
        int* getBind(){return this->bind;}
        void setName(String name){this->name = name;}
        void setPswd(String pswd){this->pswd = pswd;}
        void setAddr(String addr){this->addr = addr;}
        void setUart(int rate, int stop, int parity ){
            this->uart[0] = rate;
            this->uart[1] = stop;
            this->uart[2] = parity;
        }
        void setRole(int role){this->role = role;}
        void setCmode(int cmode){this->cmode = cmode;}
        void setBind(int addr1, int addr2, int addr3){
            this->bind[0] = addr1;
            this->bind[2] = addr2;
            this->bind[3] = addr3;
        }   
};