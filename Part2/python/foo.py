# Python 3.3.3 and 2.7.6
# python fo.py

import threading

# Potentially useful thing:
#   In Python you "import" a global variable, instead of "export"ing it when you declare it
#   (This is probably an effort to make you feel bad about typing the word "global")
i = 0
lock = threading.Lock()


def incrementingFunction():
    global i
    lock.acquire()
    for j in range(1000000):
        i += 1
    lock.release()


def decrementingFunction():
    global i
    lock.acquire()
    for k in range(1000000):
        i -= 1
    lock.release()



def main():
    global i

    incrementing = threading.Thread(target = incrementingFunction, args = (),)
    decrementing = threading.Thread(target = decrementingFunction, args = (),)
    
    incrementing.start()
    decrementing.start()
    
    incrementing.join()
    decrementing.join()
    
    print("The magic number is %d" % (i))


main()
