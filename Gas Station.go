func canCompleteCircuit(gas []int, cost []int) int {
	n := len(gas)

	totalGas := 0
	for _, x := range gas {
		totalGas += x
	}

	totalDistance := 0
	for _, x := range cost {
		totalDistance += x
	}

	if totalGas < totalDistance {
		return -1
	}

	minIndex := 0
	minGas := 0

	currentGas := gas[0]

	for i := 1; i < n; i++ {
		currentGas -= cost[i-1]
		if currentGas < minGas {
			minGas = currentGas
			minIndex = i
		}
		currentGas += gas[i]
	}

	return minIndex
}
