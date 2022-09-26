class BPBlinken : public IBlinkProgram {
private:
    uint8_t mCurrentScaler;
    uint8_t mScale;     

public:
    BPBlinken(List<ILED*>* LEDs, uint8_t scale) {
        setLEDs(LEDs);
        mCurrentScaler = 1;
        mScale = scale;
    };

private:
    void LEDOn() {
        if(mCurrentLED != 0) {
            (*mCurrentLED)->on();
        }
    }

    void LEDOff() {
        if(mCurrentLED != 0) {
            (*mCurrentLED)->off();
        }
    }
    
    void switchNextLED() {
        LEDOff();
        nextLED();
        LEDOn();
    }
    
public:
    void start() {
        mCurrentScaler = 1; //reset scaler to "1"
        mCurrentLED = mLEDs->begin();
        LEDOn();
    }

    void step() {
        if(mCurrentScaler == mScale) {
            switchNextLED();
            mCurrentScaler=1;
        } else {
            mCurrentScaler++;
        }
    }
    
    void stop() {
        LEDOff();
        mCurrentLED = mLEDs->end();
    }
};
