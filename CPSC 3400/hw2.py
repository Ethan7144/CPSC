#Ethan Tarlov
#hw2.py
#CPSC 3400
#1/30/2022

import sys
import os

class EmptyFileError(Exception): pass
class ImproperTimeError(Exception): pass

def create_time_list(input):
    '''
    Exceptions will run if the file has an error
    '''
    try:
        if not os.path.getsize(input):
            raise EmptyFileError
        finished = process_file(input)
            
    except FileNotFoundError as fail: 
        print (fail)
        sys.exit()

    except EmptyFileError:
        print('Error: File given is Empty.')
        sys.exit()

    except ImproperTimeError:
        print('Error: Time Format is Invalid.')
        sys.exit()

    else:
        return finished

def process_file(input):
    ''' 
    Function  to create the tuple list for time in the format of:
    (H, M, period)
    '''
    time = []
    for lines in open(input):
        temp = []
        count = 0
        for read in lines.split():
            if int(read.isdigit()):
                read = int(read)
                if (count == 0 and (read < 0 or read > 13)):
                    raise ImproperTimeError
                elif (count == 1 and (read < 0 or read > 60)):
                    raise ImproperTimeError
                temp.append(read)
                count += 1
            elif (count == 2 and not (read == 'AM' or read == 'PM')):
                raise ImproperTimeError
            elif count != 2 and not int(read.isdigit()):
                raise ImproperTimeError
            else:
                temp.append(read)
                count = 0             
        time.append(tuple(temp))
    return time

def second_conversion(time):
    ''' 
    converts time in the format of seconds
    '''
    hour = time[0] * 3600
    minutes = time[1] * 60
    if time[2] == 'PM' and time[0] != 12:
        hour += 43200
    return hour + minutes

def convert_time_differences(target, time):
    ''' 
    Will return the difference between two times
    '''
    newTime = time - target
    hours, remain = divmod(newTime, 3600)
    minutes, nothing = divmod(remain, 60)
    if hours <= -1:
        hours += 24
    return (hours,minutes)

def time_compare_gener(target_time,time_list):
    ''' 
    Finds the difference of tuple time with target time
    '''
    time_seconds = second_conversion(target_time)
    for i in time_list:
        temp = second_conversion(i)
        difference = convert_time_differences(time_seconds,temp)
        yield difference

def convert_to_string(time):
    ''' 
    Converts Time in the original format of H,M,period
    '''
    hour = str(time[0])
    minute = '{0:02}'.format(time[1])
    period = str(time[2])
    time_string = hour + ':' + minute + ' ' + period
    return time_string

def print_list(time):
    '''
    Prints Time in the original format of H,M,AM/PM
    '''
    list = []
    for time in time_list:
        list.append(convert_to_string(time))
    print(list)

def max_printer(time):
    '''
    used specifically for printing the max time in a tuple
    '''
    return convert_to_string(time)

#1 and #2
time_list = create_time_list(sys.argv[1])
# 4
print_list(time_list)
# 5
print(max(time_list, key=max_printer))
# 6
print(sorted(time_list, key=second_conversion))
# 7
target = time_list[0]
# 8
compare = [x for x in time_compare_gener(target,time_list)]
print(compare)