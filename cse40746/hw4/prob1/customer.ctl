load data infile 'customer.csv'
insert into table customer
fields terminated by "," optionally enclosed by '"'
(cust_id,cust_name,city,country,beg_bal,cur_bal)
