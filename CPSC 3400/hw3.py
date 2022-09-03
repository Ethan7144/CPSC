#Ethan Tarlov
#CPSC 3400
#2/6/22
#hw3.py

import sys

def mark_sweep (filename):
    ''' 
        The actual mark and sweep algorithm, will process the file and run it in the mark and sweep
        Will return a dictionary with the marked and swept nodes as the result
    '''
    pointer = {}
    node_block = []
    tracer = []
    # Process file and put it in dictionary
    with open(filename, 'r') as file:
        for line in file:
            read = line.strip().split(',')
            node_block.append(read)
            if not int(read[0].isdigit()):
                pointer[read[0]] = [int(read[1])]
            if (len(read) == 1):
                tracer.append(int(read[0]))
            else:
                tracer.append(int(read[1])) # Once put in, it will begin to mark and sweep
    # Get rid of any duplicate numbers
    swept = list(set(tracer))
    
    # Starts tracking through the list to see if any key
    # is a block, will add the 2nd if the 1st value is found
    for i in node_block: 
        for j in pointer:
            if int(i[0].isdigit()) and len(i) != 1:              
                if int(i[0]) in pointer[j]:
                    pointer[j].append(int(i[1]))
    
    # Creates a temp variable to remove any numbers from 
    # the swept list
    temp = []
    for i in swept:
        temp.append(i) 
    for x in temp:
        for keys in pointer:
            if x in pointer[keys]:
                if x in swept:
                    swept.remove(x)
    
    # Creates a dictionary to return all marked and Swept Nodes
    finished = {'marked': [], 'swept': []}
    for mark in pointer:
        for element in pointer[mark]:
            if element not in finished['marked']:
                finished['marked'].append(element)
    finished['marked'] = sorted(finished['marked'])
    finished['swept'] = swept
    return finished

# 1,2,3
printing = mark_sweep(sys.argv[1])
# 4
print('Marked: ', end ='')
for mark in printing['marked']:
    print(mark, end=' ')
print()
# 4
print('Swept: ', end ='')
for sweep in printing['swept']:
    print(sweep, end=' ')