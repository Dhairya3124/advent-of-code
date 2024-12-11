package main

import (
	"fmt"
	"log"
	"os"
	"strconv"
	"strings"
)
func convertInt(str string)int{
	ans,err := strconv.Atoi(str)
	if err != nil {
		log.Fatal(err)
	}
	return ans

}
func getVal(m map[string]int,key string)int{
if val, exists := m[key]; exists {
	return val
}
return 0
}
func blink(n string) []string {
	if n == "0"{
		return []string{strconv.Itoa(1)}
	}else if len(n)%2 == 0 {
		    mid := len(n) / 2
		    return []string{strconv.Itoa(convertInt(n[:mid])), strconv.Itoa(convertInt(n[mid:]))}
		  }else{
		return []string{strconv.Itoa(convertInt(n)*2024)}
	}

}
func solve(steps int,input string)int{
	currentStep:=make(map[string]int)
	vals:=strings.Split(input, " ")
	for _,val:=range vals{
		currentStep[val] = 1

	}
	  for i := 0; i < steps; i++ {
		nextStep := make(map[string]int)

	for key := range currentStep {	for _,val:=range blink(key){
			nextStep[val] = getVal(nextStep,val) + getVal(currentStep,key) 
		}
		

	}
	currentStep = nextStep
}

sum := 0
for _, count := range currentStep {
	sum += count
}
return sum
}

func main() {
	fileName := "./input.txt"
	inputByte,err:=os.ReadFile(fileName)
	if err != nil {
		fmt.Println(err)

	}else{
		input:=string(inputByte);
		fmt.Println("1",solve(25,input))
		fmt.Println("2",solve(75,input))

	}

}
