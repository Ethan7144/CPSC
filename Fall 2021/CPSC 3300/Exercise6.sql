create table orders(
orderNumber int1 primary key,
status varchar(10)
);

insert into orders values(1, 'shipped'),
(2,'resolved'),
(3,'shipped'),
(4,'cancelled'),
(5,'in process'),
(6,'in process');

delimiter |
create Procedure countStatus(IN statusType varchar(10), OUT count INT)
BEGIN
	Select COUNT(status)  INTO count  FROM orders WHERE status = statusType;
    END;
    |
    
set @status = 'resolved';
call CountStatus(@status,@total);
select @status, @total;