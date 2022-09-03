#Ethan Tarlov
#CPSC 3300
#HW6

#Number 1

select NOW();
Insert into orders values (10426, '2021-11-29', '2021-12-03', '2021-12-01', 'in process', NULL, 145);
Insert into orderdetails values(10426, 'S18_1749', 30, 136, 1),
(10426, 'S18_2248', 50, 55.09, 2);

#2

DELIMITER |
CREATE PROCEDURE setRelocationFee(in employeeID int (11), out FEE int)
BEGIN
	Declare OFFCODE varchar(10);
    Select officeCode into OFFCODE
    FROM employees
    where employeeNumber = employeeID;
    if OFFCODE = '1' THEN
    SET FEE = 10000;
    ELSEIF OFFCODE = '2' THEN
    SET FEE = 8000;
    ELSEIF OFFCODE = '7' THEN
    SET FEE = 20000;
    ELSE SET FEE = 15000;
    END IF;
END;
|

set @employeeID = 1501; 
call setRelocationFee(@employeeID, @relocationfee); 
select @employeeID, @relocationfee; 
    
#3

DELIMITER |
CREATE PROCEDURE changeCreditLimit(in customerID int (11), PAYMENT int)
BEGIN
	DECLARE CheckLimit double;
    select creditLimit into CheckLimit
    from customers
    where customerNumber = customerID;
    IF PAYMENT < CheckLimit THEN
		UPDATE customers
        SET creditLimit = creditLimit + 2000
        WHERE customerNumber = customerID;
	END IF;
END;
|

select creditLimit from customers where customerNumber = 114;
set @customer = 114; 
set @totalpayment = 15000; 
call changeCreditLimit(@customer,@totalpayment); 

    
#4
create table odd (number int primary key); 

DELIMITER |
CREATE PROCEDURE insertOdd()
BEGIN
	DECLARE X INT;
	set x = 1;
    while x != 21 do
    insert into odd(number) values (x);
    if x = 5 then
    delete from odd where number = x;
    elseif x = 15 then 
    delete from odd where number = x;
    end if;
    set x = x + 2;
    end while;
END;
|

select creditLimit from customers;


call insertOdd();

select * from odd;
    