--Eric Layne hw5
--q6

select r.region_name, s.num_states
from (
	select region_code, count(*) as num_states
	from statesinfo
	group by region_code
	order by region_code
) s, regions r
where s.region_code = r.region_code;

exit;
