load data infile 'sale.csv'
insert into table sale
fields terminated by "," optionally enclosed by '"'
(sale_id,sdate DATE "MM/DD",cust_id,salpers_id,prod_id,qty)
