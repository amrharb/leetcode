class ParkingSystem {
public:
    int pos[4];
    ParkingSystem(int big, int medium, int small) {
        pos[1]=big;
        pos[2]=medium;
        pos[3]=small;
    }
    
    bool addCar(int carType) {
        pos[carType]--;
        if(pos[carType]<0)return 0;
        else return 1;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */