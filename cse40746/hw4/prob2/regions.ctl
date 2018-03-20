load data infile 'regions.csv'
insert into table regions
fields terminated by "," optionally enclosed by '"'
(region_code,region_name)
