class BlinkeLicht {
private:
    IBlinkProgram* mBlinkPrograms[5];
    uint8_t mBlinkProgramsAddIndex;
    IBlinkProgram* mCurrentBlinkProgram;
    uint8_t mCurrentProgramIndex;
    const uint8_t mCurrentProgramMax;
    
public:
    BlinkeLicht() : mCurrentProgramMax(5){
        mCurrentBlinkProgram = 0;
        mCurrentProgramIndex = 0;
        for(uint8_t i = 0; i < mCurrentProgramMax; i++) {
            mBlinkPrograms[i] = 0;
        }
        mBlinkProgramsAddIndex = 0;
    };
    
private:
    void start_program() {
        if(mCurrentBlinkProgram != 0) {
            mCurrentBlinkProgram->start();
        } else {
            //Set to first Programm, when not initialized
            mCurrentBlinkProgram = mBlinkPrograms[0];
            if(mCurrentBlinkProgram != 0) {
                mCurrentBlinkProgram->start();
            }
        }
    }
    
    void next_program() {
        mCurrentProgramIndex++;
        if(mCurrentProgramIndex == mCurrentProgramMax) {
            mCurrentProgramIndex = 0;   
        }
        mCurrentBlinkProgram = mBlinkPrograms[mCurrentProgramIndex];
    }

    void stop_program() {
         if(mCurrentBlinkProgram != 0) {
            mCurrentBlinkProgram->stop();
        }
    }

    void step_program() {
        if(mCurrentBlinkProgram != 0) {
            mCurrentBlinkProgram->step();
        }
    }
    
public:
    void addProgramm(IBlinkProgram* bp) {
        if(mBlinkProgramsAddIndex < mCurrentProgramMax) {
            mBlinkPrograms[mBlinkProgramsAddIndex] = bp;
            mBlinkProgramsAddIndex++;
        }
    }
    
    void start() {
        start_program();
    }
    
    //switch to next program
    void next() {
        stop_program();
        next_program();
        start_program();
    }
    
    void stop() {
        stop_program();
    }
    
    //trigger program every 100ms.
    // This is NOT threadsafe with next()!!!
    // On AVR there are no nested interrupts. So when next() and step() are only called in the same or different interrupts, it's okay.
    void step() {
        step_program();
    }
};
