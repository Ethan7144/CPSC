#Ethan Tarlov
#HW5
#CPSC 3300


#1

Select STUDENT_ID, Courses.COURSE_CODE, COURSE_CREDITS
From Registration, Courses
Where Courses.COURSE_CODE = Registration.COURSE_CODE and STUDENT_ID = '861103-2438';


#2
Select Registration.STUDENT_ID, Registration.COURSE_CODE, STUDENT_FNAME, STUDENT_LNAME, COURSE_CREDITS
From Registration, Students, Courses 
Where Registration.STUDENT_ID = Students.STUDENT_ID and Registration.COURSE_CODE = Courses.COURSE_CODE
Group by COURSE_CODE;

#3

Select Registration.STUDENT_ID, STUDENT_FNAME, STUDENT_LNAME, AVG(REGISTRATION_GRADE) AS AVG_GRADE
From Registration, Students
Where Registration.STUDENT_ID = Students.STUDENT_ID
Group by STUDENT_ID;

#It is Adam Johnson who has the highest avg grade with a 3.833



#4
Select Registration.STUDENT_ID, STUDENT_FNAME, STUDENT_LNAME, COURSE_CODE
From Registration, Students
Where Registration.STUDENT_ID = Students.STUDENT_ID and COURSE_CODE = 'CS056';

#5
Select Students.STUDENT_ID, STUDENT_FNAME, STUDENT_LNAME, Courses.COURSE_NAME, Registration.COURSE_CODE
From Students
Left join Registration ON Students.STUDENT_ID = Registration.STUDENT_ID
Left Join Courses ON Courses.COURSE_CODE = Registration.COURSE_CODE
Where Registration.COURSE_CODE = 'CS056' OR Registration.COURSE_CODE = 'CS010';

#Adam Johnson and Bo Ek

#6

Create View Course_List as
Select Students.STUDENT_ID, STUDENT_FNAME, STUDENT_LNAME, Courses.COURSE_NAME, Registration.COURSE_CODE
From Students
Left join Registration ON Students.STUDENT_ID = Registration.STUDENT_ID
Left Join Courses ON Courses.COURSE_CODE = Registration.COURSE_CODE
Group by STUDENT_ID;



#7 

Select Students.STUDENT_ID, STUDENT_FNAME, STUDENT_LNAME, Courses.COURSE_NAME, Registration.COURSE_CODE
From Students
Left join Registration ON Students.STUDENT_ID = Registration.STUDENT_ID
Left Join Courses ON Courses.COURSE_CODE = Registration.COURSE_CODE
Where Registration.COURSE_CODE = 'CS056' OR Registration.COURSE_CODE = 'CS010' or Registration.COURSE_CODE = 'CS052'
GROUP BY STUDENT_ID;

#2 
create table Inventory (
itemid varchar(20) primary key, name varchar(30),
price decimal(6,2),
quantity int
);
create table Transaction (
transid int auto_increment primary key, itemid varchar(20),
quantity int,
time datetime,
foreign key (itemid) references Inventory(itemid) );
create table Inventory_history (
id int auto_increment primary key, itemid varchar(20),
action varchar(20),
oldprice decimal(6,2),
time datetime,
foreign key (itemid) references Inventory(itemid)
);

#1
DELIMITER |
CREATE Trigger insert_inventory AFTER INSERT ON Inventory
FOR EACH ROW BEGIN 
	INSERT INTO Inventory_history SET itemid = NEW.itemid;
    INSERT INTO Inventory_history SET time = datetime;
    INSERT INTO Inventory_history SET action = 'Add an item';
    INSERT INTO Inventory_history SET oldprice = NULL;
END;
|

#2
DELIMITER |
CREATE Trigger change_quantity AFTER INSERT ON Transaction
FOR EACH ROW BEGIN 
	UPDATE Inventory SET quantity = quantity - 1 WHERE quantity = new.quantity;
END;
|

#3 
DELIMITER |
CREATE Trigger change_price BEFORE UPDATE ON Inventory
FOR EACH ROW BEGIN 
	INSERT INTO Inventory_history SET itemid = NEW.itemid;
    INSERT INTO Inventory_history SET time = datetime;
    INSERT INTO Inventory_history SET action = 'price change';
    INSERT INTO Inventory_history SET oldprice = price;
END;
|

