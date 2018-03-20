--Eric Layne hw5
--q5


select *
from (
	select state_abv, count(*) as num_city
	from (
		select state_abv, city
		from allzips
		group by state_abv, city 
		order by state_abv, city
	)
	group by state_abv
	order by num_city desc
)
where rownum < 11;

exit;
