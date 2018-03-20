--Eric Layne hw5
--q3

select *
from (
	select city, count(*) as num_zips
	from allzips
	group by city, state_abv
	order by num_zips desc
)
where rownum = 1;

exit;
