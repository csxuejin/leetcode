package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strings"
	"testing"
)

//func Test_findAnagrams(t *testing.T) {
//	findAnagrams("abaacbabc", "abc")
//}

func Test_Refactor(t *testing.T) {
	dir := "/Users/jinxue/Desktop/leetcode/golang"
	files, err := ioutil.ReadDir(dir)
	if err != nil {
		panic(err)
	}

	for _, f := range files {
		if strings.HasSuffix(f.Name(), ".go") {
			subDir := dir + "/" + strings.TrimSuffix(f.Name(), ".go")

			if err = os.MkdirAll(subDir, os.ModePerm); err != nil {
				fmt.Printf("err: %v", err)
				panic(err)
			}

			oldLocation := dir + "/" + f.Name()
			newLocation := subDir + "/" + f.Name()
			if err = os.Rename(oldLocation, newLocation); err != nil {
				panic(err)
			}

			fmt.Printf("create file: %v", newLocation)
		}
	}
}
