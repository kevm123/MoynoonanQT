#include "key.h"

Key::Key(string inDescription, int inWeightGrams, float inValue,
         string inplaced, bool obt, string inString, bool inIsKey, int inKeyNum) : Item(inDescription, inWeightGrams,
                                                                                         inValue,inplaced, obt, inString,
                                                                                        inIsKey)

{

    keyNum = inKeyNum;
    cout << "keyNum = " << keyNum << endl;
    cout << description << endl;
}

int Key::getKeyNum(){
    return keyNum;
}
