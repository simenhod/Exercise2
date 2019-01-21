package main

import (
	. "fmt"
	"runtime"
	"time"
)

var i = 0

func incrementing() {
	for count := 0; count < 1000000; count++ {
		i++
	}
}

func decrementing() {
	for count := 0; count < 1000000; count++ {
		i--
	}
}

func main() {
	runtime.GOMAXPROCS(runtime.NumCPU()) // I guess this is a hint to what GOMAXPROCS does...
	// Try doing the exercise both with and without it!
	go incrementing() // This spawns someGoroutine() as a goroutine
	go decrementing() // This spawns someGoroutine() as a goroutine

	// We have no way to wait for the completion of a goroutine (without additional syncronization of some sort)
	// We'll come back to using channels in Exercise 2. For now: Sleep.
	time.Sleep(100 * time.Millisecond)
	Println("Value of i is: ", i)
}
