package main

type DetectSquares struct {
	countXY map[int]map[int]int
	countYX map[int]map[int]int
}

func abs(x int) int {
	if x >= 0 {
		return x
	}
	return -x
}

func Constructor() DetectSquares {
	return DetectSquares{
		countXY: make(map[int]map[int]int),
		countYX: make(map[int]map[int]int),
	}
}

func (this *DetectSquares) Add(point []int) {
	if this.countXY[point[0]] == nil {
		this.countXY[point[0]] = make(map[int]int)
	}
	this.countXY[point[0]][point[1]]++

	if this.countYX[point[1]] == nil {
		this.countYX[point[1]] = make(map[int]int)
	}
	this.countYX[point[1]][point[0]]++
}

func (this *DetectSquares) Count(point []int) int {
	res := 0

	for y, countY := range this.countXY[point[0]] {
		if y == point[1] {
			continue
		}
		for x, countX := range this.countYX[point[1]] {
			if x == point[0] {
				continue
			}
			if abs(point[0]-x) == abs(point[1]-y) {
				res += countX * countY * this.countXY[x][y]
			}
		}
	}

	return res
}
