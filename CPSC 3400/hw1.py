# Ethan Tarlov
# HW1
# CPSC 3400
# 1/18/2022

import sys

def process_file(file):
    '''
    Reads and parses the input file. 
    Creates and returns a dictionary consisting of key-value pairs where
    the key is a color and the value is a tuple consisting of three integers: 
    (number of 1st place votes, number of 2nd place votes, number of 3rd place votes). 
    The dictionary only contains colors that appeared in the file.
    '''

    fd = open(file,'r')
    dictionary = {}
    tracker = 0  # tracks the place of ranking for a color
    for i in fd:
        for j in i.split():
            if j in dictionary: # if a color is in dictionary
                dictionary[j][tracker] += 1

            else:
                dictionary[j] = [0,0,0]
                dictionary[j][tracker] += 1

            tracker += 1
        tracker = 0
    for i, j in dictionary.items():
        dictionary[i] = tuple(j)
    fd.close()
    return dictionary

def get_first_place_votes(dictionary, color):
    '''
    Returns the number of 1st place votes (possibly zero) for the provided color.
    '''
    if color in dictionary:
        return dictionary[color][0]
    return 0

def create_favorite_color_list(dictionary):
    '''
    Returns an ordered list of colors based on the number of 1st place votes. 
    The first item in the list is the color that had the most 1st place votes.
    The second item in the list is the color that had the second most 1st place votes. 
    The list only contains colors that receive at least one 1st place vote. 
    Ties are broken as follows: 1) winner is the color with higher number of 2nd place votes, 
    2) if still tied, winner is the color with higher number of 3rd place votes,
    3) if still tied, winner is the color that appears earlier in alphabetical order.
    '''
    colors = []
    temp = {}

    for i, j in dictionary.items():
        temp[i] = int(j[0])
    for i in temp:
        top = 0
        color = ''

        for j, k in sorted(temp.items()):
            if k > 0:
                if k > top: # checking if color already exists in the list
                    temp_top = k
                    temp_color = j
                    if temp_color not in colors:
                        top = temp_top
                        color = temp_color
        colors.append(color)
    colors = list(filter(None,colors))
    return colors

def create_color_score_dict(dictionary):
    '''
    Creates and returns a dictionary consisting of key-value pairs where the key is a color and the value
    is an integer that is computed using the following formula (number of 1st place votes x 3) + 
    (number of 2nd place votes x 2) + (number of 3rd place votes). 
    The dictionary only contains colors that appeared in the file.
    '''
    tier = {}
    for i, j in dictionary.items():
        tier[i] = (j[0]*3) + (j[1]*2) + j[2]
    return tier
def print_dictionary(dictionary):
    '''
    Prints the dictionary in sorted order (use sorted function). 
    Print each entry on a separate line in the following format:
    key: value
    '''

    for i,j in sorted(dictionary.items()):
        x = i
        y = j
        print('{: < 7}'.format(x),y)
    


# This part is testing the functions as instructed in HW1 instructions

dictionary = process_file(sys.argv[1])
print_dictionary(dictionary)

blue = get_first_place_votes(dictionary, 'blue')
print(blue)

green = get_first_place_votes(dictionary, 'green')
print(green)

color_list = create_favorite_color_list(dictionary)
print(color_list)

color_score = create_color_score_dict(dictionary)
print_dictionary(color_score)