class BPLeuchten : public IBlinkProgram {
private:
    
public:
    BPLeuchten(ILED* LEDs[]) {
        setLEDs(LEDs);
        mCurrentLEDmax = 3;
        mCurrentLEDindex = 0;
    };
    
    void start() {
        for(uint8_t i = 0; i < mCurrentLEDmax; i++) {
            mLEDs[i]->on();
        }
    }

    void step() {
        //nothing to do;
    }
    
    void stop() {
        for(uint8_t i = 0; i < mCurrentLEDmax; i++) {
            mLEDs[i]->off();
        }
    }
};
