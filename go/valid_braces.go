package main

import "fmt"

// Braces Balanced checker with stack in GO
// Jacob Lowe

func main(){
  tests := [8]string{"()","{{","{{}}","((",")","(){}[]","[({)](]","(((({{{[[([])]]}}}))))"}
  for _, i := range tests{
    fmt.Println(i,"is",ValidBraces(i))
  }
}

type Stack []rune

func (s *Stack) Push(c rune){
  *s = append(*s, c)
}

func (s *Stack) Pop()rune{
  res := (*s)[len(*s)-1]
  *s = (*s)[:len(*s)-1]
  return res
}

func (s *Stack)  Length()int{
  return len(*s)
}

func ValidBraces(str string) bool {
  // Stack for validating braces
  s := &Stack{}
  open := map[rune]bool{'(': true, '{': true, '[': true}
  closed := map[rune]bool{')': true, '}': true, ']': true}
  for _, c := range str{
    if open[c]{
      s.Push(c)
    }else if closed[c]{
      // Cant pop stack with no size
      if (s.Length() == 0){
        return false
      }
      switch valid := s.Pop(); valid{
        case '(':
          if c != ')' {return false}
        case '{':
          if c != '}' {return false}
        case '[':
          if c != ']' {return false}
        default:
          fmt.Println("Unknown open bracket type", valid)
      }
    }
  }
  // Opening braces remaining
  if (s.Length() != 0){
    return false;
  }
  return true 
}
