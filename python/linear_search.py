def search(arr, search_Element):
	left = 0
	length = len(arr)
	position = -1
	right = length - 1
	for left in range(0, right, 1):
		# left 
		if (arr[left] == search_Element):
			position = left
			print("Element found in Array at ", position +
				1, " Position with ", left + 1, " Attempt")
			break
		# right
		if (arr[right] == search_Element):
			position = right
			print("Element found in Array at ", position + 1,
				" Position with ", length - right, " Attempt")
			break
		left += 1
		right -= 1
	if (position == -1):
		print("With ", left ,"attempt, the array was not found")
arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
search_element = 1
search(arr, search_element)


