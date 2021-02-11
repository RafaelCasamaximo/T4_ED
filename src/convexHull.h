#ifndef __CONVEXHULL_H_
#define __CONVEXHULL_H_

    #include "doublyLinkedList.h"
    #include "point.h"

    DoublyLinkedList convexHull(DoublyLinkedList l, Point (*getPoint)(Info), void (*swapInfo)(Info, Info));


#endif