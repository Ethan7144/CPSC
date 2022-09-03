# Ethan Tarlov 
# HW4 
# CPSC 3300
#1
Create Table Students(
	STUDENT_ID CHAR(11) PRIMARY KEY,
	STUDENT_FNAME VARCHAR(20),
    STUDENT_LNAME VARCHAR(20),
    STUDENT_GENDER CHAR(1),
    STUDENT_DATEOFBIRTH DATE
);
Create Table Courses(
	COURSE_CODE VARCHAR(6) PRIMARY KEY,
	COURSE_NAME VARCHAR(70),
    COURSE_LEVEL CHAR(2),
    COURSE_CREDITS INT
);
Create Table Registration(
	STUDENT_ID CHAR(11),
	COURSE_CODE VARCHAR(6),
    REGISTRATION_GRADE DECIMAL(2,1),
    FOREIGN KEY(STUDENT_ID) references Students(STUDENT_ID),
    FOREIGN KEY(COURSE_CODE) references Courses(COURSE_CODE)
);
#2
insert into Students values ('861103-2438','Adam','Johnson','M' ,'1990-10-01'); 
 
insert into Students values ('911212-1746','Eva',  'Smith',  'F',  '1991-08-20'),
('950829-1848',  'Anna',  'Washington',  'F',  '1993-09-26'),
('123456-0980',  'Eric',  'Alonzo',  'M',  '1990-05-26'),
('908023-2456',  'Bo',  'Ek',  'M',  '1992-03-15'), 
('098735-3456',  'Danny',  'Goss',  'M',  '1992-02-01'),
('124345-3430', 'Mike',  'White',  'M',  '1995-06-10'),
('124568-1345', 'Emily',  'Young',  'F',  '1995-04-28'), 
('908409-0010',  'Cathy',  'Lee',  'F',  '1993-10-06'), 
('124587-9088',  'Ben',  'Woo',  'M',  '1992-11-30'), 
('120953-0909',  'Anna',  'Washington',  'F',  '1990-10-09'),
('120449-1008',  'John', 'Goss',  'M',  '1995-10-26');

insert into Courses values ('CS056',  'Database Systems',  'G1',  '5');
insert into Courses values ('CS010',  'C++',  'U1',  '5'),
('ENG111',  'English',  'U1',  '3'), 
('FIN052',  'Finance',  'G1',  '5'), 
('PHY210',  'Physics',  'U2',  '5'),
('CHE350',  'Chemistry',  'U3',  '5'),
('BIO001',  'Biology',  'U1',  '3'),
('CS052',  'Operating Systems',  'G1',  '5' );

insert into Registration values ('861103-2438',  'CS056',  4);
insert into Registration values ('861103-2438',  'CS010',  4),
('861103-2438',  'PHY210',  3.5),
('911212-1746',  'ENG111',  2),
('950829-1848',  'CHE350',  3),
('950829-1848',  'BIO001',  2.5),
('123456-0980',  'CS052',  3.5),
('123456-0980',  'CS056',  4),
('908023-2456',  'PHY210',  3.0),
('908023-2456',  'CS056',  1.0),
('908023-2456',  'CS010',  2.0),
('124345-3430',  'FIN052',  2.5),
('124345-3430',  'CHE350',  4),
('908409-0010',  'CS052',  2),
('124587-9088',  'BIO001',  4), 
('124587-9088',  'CS052',  3.5);

#3
Select STUDENT_FNAME, STUDENT_LNAME
From Students
group by STUDENT_FNAME
order by STUDENT_FNAME;

#4
Select STUDENT_ID, STUDENT_FNAME, STUDENT_LNAME, STUDENT_DATEOFBIRTH, STUDENT_GENDER
From Students
where STUDENT_GENDER = 'F' AND STUDENT_DATEOFBIRTH < '1992-12-31';

#5
Select STUDENT_ID, COURSE_CODE
From Registration
where COURSE_CODE = 'PHY210';

# The answer is 2

# 6
Select COURSE_CODE, COURSE_NAME 
From Courses
Where COURSE_CODE = 'CS056' OR COURSE_CODE = 'CS010' OR COURSE_CODE = 'CS052';

# The answer is 3

#7
Select * From Courses
Where COURSE_LEVEL = 'G1' AND COURSE_CREDITS = '5';

# The answer is 3

#8
Select * From Courses
Where COURSE_LEVEL = 'G1';
#G1 has 3
Select * From Courses
Where COURSE_LEVEL = 'U2';
# U2 has 1
Select * From Courses
Where COURSE_LEVEL = 'U1';
# U1 has 3
Select * From Courses
Where COURSE_LEVEL = 'U3';
#U3 has 1

#9

Select STUDENT_ID, AVG(REGISTRATION_GRADE) AS AVG_GRADE
From Registration
where STUDENT_ID = '861103-2438';

#Answer is 3.8333

#10

Select STUDENT_ID, COURSE_CODE, REGISTRATION_GRADE
From Registration
where COURSE_CODE = 'CS052'
order by REGISTRATION_GRADE;

# 123456-0980 and 124587-9088 have the highest grade

#11

Select *
From Registration
Where STUDENT_ID = '123456-0980' OR STUDENT_ID = '861103-2438';

#12
Select Students.STUDENT_ID, Registration.COURSE_CODE
From Students 
Left Join Registration on Students.STUDENT_ID = Registration.STUDENT_ID
Order by Students.STUDENT_ID;

# The answer is 4 students have not registered

# 13

Select STUDENT_ID, SUM(REGISTRATION_GRADE) AS SumOfGrade, AVG(REGISTRATION_GRADE) AS AVG_GRADE
From Registration
Group by STUDENT_ID
Having AVG_GRADE < 3;

# 14
Select STUDENT_ID, Count(COURSE_CODE) AS TOTAL_COURSES, COURSE_CODE
From Registration 
Group by STUDENT_ID
Having TOTAL_COURSES >= 3
Limit 1;

# 15
Select STUDENT_ID, COURSE_CODE
From Registration 
where COURSE_CODE = 'PHY210' OR COURSE_CODE = 'BIO001';

# 16
Select STUDENT_ID, STUDENT_FNAME, STUDENT_LNAME, STUDENT_DATEOFBIRTH
From Students
where STUDENT_DATEOFBIRTH = (select max(STUDENT_DATEOFBIRTH) from Students);

# 17

Select STUDENT_ID, COURSE_CODE
From Registration
where COURSE_CODE = 'CS056';

Select STUDENT_ID, COURSE_CODE
From Registration
where COURSE_CODE != 'CS056' AND STUDENT_ID != '861103-2438' AND STUDENT_ID != '123456-0980' AND STUDENT_ID != '908023-2456';

# The answer is 5

# 18
Update Courses set COURSE_CREDITS = '6'
Where COURSE_CODE = 'CS056' OR COURSE_CODE = 'CS052' OR COURSE_CODE = 'CS010' AND COURSE_CREDITS = '5';

# 19

Delete from Registration where STUDENT_ID = '908409-0010';
Delete From Students where STUDENT_ID = '908409-0010';
