--Eric Layne hw5
--q4

select *
from (
	select city, count(city) as num_name
	from (
		select distinct(city), state_abv
		from allzips
	)
	group by city
	order by num_name desc
)
where rownum < 11;

exit;
