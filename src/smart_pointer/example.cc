// Copyright 2020 yht SegmentFaultCPP
// smart pointer testing

#include "./smart_pointer.h"

int main(int argc, char** argv) {
    using algor_yht::smart_pointer::SmartPointer;
    SmartPointer ptr(new int(122));
    return 0;
}
