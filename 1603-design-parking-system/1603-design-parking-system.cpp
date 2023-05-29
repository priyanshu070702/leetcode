class ParkingSystem {
public:
    int x , y, z;
    ParkingSystem(int big, int medium, int small) {
        x = big,y = medium,z = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1){
            if(x>0){
                x--;
                return true;
            }else return false;
        }else if(carType == 2){
                if(y>0){
                    y--;
                    return true;
                }return false;
            }else if(carType == 3){
                if(z>0){
                    z--;
                    return true;
                }return false;
            }
            return false;
    }
};
/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */