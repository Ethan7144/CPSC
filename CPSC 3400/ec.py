# Ethan Tarlov
# 3/5/22
# Extra Credit


import csv
import re

 #write exceptions for:
 #INVALID_CSV
 #INVALID_SYNTAX (regex required) new syntax checker function...
 #OPERATION_EXCEPTION

class InvalidPipelineSyntaxError(Exception): 
    pass

class InvalidDataError(Exception): 
    pass

class InvalidColumnName(Exception): 
    pass

def csv_writer(output, csv_filename):
    '''
    The output file will be written in the form:
    "{'quotient': (0.6666666666666666, 0.7142857142857143)}"
    where the key of the dictionary is the name of the row and the values after 
    it are the column values from top (left most) to bottom (right most)
    '''
    with open(csv_filename, 'w') as file:
    # create the csv writer
        writer = csv.writer(file)

    # write a row to the csv file
        writer.writerow(output)

def csv_reader(csv_filename):
    data = []
    with open(csv_filename,'r') as file:
        csvfile = csv.reader(file) 
    
        for row in csvfile:       
            try:
                data.append(row)
            except ValueError:
                raise InvalidDataError
            except:
                continue
    print(data)
    col_names = data[0][0].split()
    print(col_names)
    data.pop(0)
    
    offset = 0
    for item in col_names:
        offset+= 1
    print('offset: ', offset)

    sum = []
    for item in data:
        sum += item
    
    stringSum = ''
    for item in sum:
        stringSum += (item + ' ')
    
    print(stringSum.split())
    data = stringSum.split()

    dict = {}
    for name in col_names:
        dict[name] = ()
    
    print(dict)

    count = 0
    auxCount = 0
    print(data)
    for name in dict.keys():
        print("THIS IS COUNT", count)
        while count <= len(data) -1:
            print(count)
            print('data: ', data[count])
            dict[name] += (data[count],)
            count+= offset

        if auxCount < offset:
            auxCount +=1
            count = auxCount

    print("final result: ", dict)

    return(dict)

def project_handler(result_list, projection_instructons):
    name_reference = {} #key is name of dict, value is dict
    items_to_write = []
    for item in result_list:
        for key in item.keys():
            name_reference[key] = item
        
    for item in name_reference.keys():
        if item in projection_instructons:
            items_to_write.append(name_reference[item])
            print(name_reference[item])
    return items_to_write

def inputChecker(pipeline, columns):
    pipeline = pipeline.split()
    print("INPUT CHECKING:", pipeline)
    val1 = pipeline[2]
    val2 = pipeline[3]
    if val1 or val2 not in columns.keys():
        raise InvalidColumnName
    return 0

def arithmetic_handler(string, inputs):
    print('starting arithmetic with', inputs)
    string = string.split()
    operator = string[1]
    input1_name = string[2]
    input2_name = string[3]
    output_name = string[4]

    result = {}
    if operator == '+':
        res1 = int(inputs[input1_name][0]) + int(inputs[input2_name][0])
        res2 = int(inputs[input1_name][1]) + int(inputs[input2_name][1])
        try:
            res3 = int(inputs[input1_name][2]) + int(inputs[input2_name][2])
            result[output_name] = (res1, res2, res3)
        except:
            result[output_name] = (res1, res2)
        return result

    elif operator == '-':
        res1 = int(inputs[input1_name][0]) - int(inputs[input2_name][0])
        res2 = int(inputs[input1_name][1]) - int(inputs[input2_name][1])
        try:
            res3 = int(inputs[input1_name][2]) - int(inputs[input2_name][2])
            result[output_name] = (res1, res2, res3)
        except:
            result[output_name] = (res1, res2)
        return result

    elif operator == '/':
        res1 = int(inputs[input1_name][0]) / int(inputs[input2_name][0])
        res2 = int(inputs[input1_name][1]) / int(inputs[input2_name][1])
        try:
            res3 = int(inputs[input1_name][2]) / int(inputs[input2_name][2])
            result[output_name] = (res1, res2, res3)
        except:
            result[output_name] = (res1, res2)
        return result
    
    elif operator == '*':
        res1 = int(inputs[input1_name][0]) * int(inputs[input2_name][0])
        res2 = int(inputs[input1_name][1]) * int(inputs[input2_name][1])
        try:
            res3 = int(inputs[input1_name][2]) * int(inputs[input2_name][2])
            result[output_name] = (res1, res2, res3)
        except:
            result[output_name] = (res1, res2)
        return result

    elif operator == '%':
        res1 = int(inputs[input1_name][0]) % int(inputs[input2_name][0])
        res2 = int(inputs[input1_name][1]) % int(inputs[input2_name][1])
        try:
            res3 = int(inputs[input1_name][2]) % int(inputs[input2_name][2])
            result[output_name] = (res1, res2, res3)
        except:
            result[output_name] = (res1, res2)
        return result


def interpret(csv_filename, filename, outFile):
    output = [] #a list to store the output of the inerpreter 
    input_dict = csv_reader(csv_filename) #read inputs from csv file

    with open (filename, 'r') as file: #read pipline definition from file 
        for row in file:
            pipeline = row
    print(pipeline)
    
    pipelines = pipeline.split('|') #get instruction sets

    print("pipelines: ",pipelines) 
    command = pipelines[0].split('=')#takes first set of insructions up until instance of '|' but after '='
    print(command[1])

    inputChecker(command[1], input_dict)

    nextInputDict = {}
    output.append(arithmetic_handler(command[1], input_dict))
    for identifier in input_dict.keys():
        if identifier not in command[1]:
            nextInputDict[identifier] = input_dict[identifier]
    print("HEY LOOK HERE!!", nextInputDict)


    pipelines.pop(0)
    print('subsequent command list:', pipelines)

    for instruction in pipelines:
        if 'arithmetic' in instruction:
            print('ORDERS', instruction)
            output.append(arithmetic_handler(instruction, nextInputDict))
            pipelines.pop(pipelines.index(instruction))

    projection = pipelines[-1] # the project call
    
    write = project_handler(output, projection)

    csv_writer(write, outFile)

if __name__ == "__main__":
    
    try:
        interpret('test.csv', 'test.pipes', 'testout.txt')
    except InvalidPipelineSyntaxError:
        print('Syntax Error')
        exit()
    except InvalidDataError:
        print('Error, Data Entered is not valid')
        exit()
    except InvalidColumnName:
        print('Error, Column Name Invalid')
        exit()
    #interpret('black_knives.csv', 'night_of_black_knives.pipes', 'testout.txt')

     #OPERATION_EXCEPTION