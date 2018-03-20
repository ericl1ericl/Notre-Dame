--Eric Layne hw5
--q2

select zip, A, B
from (
	select rownum n, a.zip, a.state_abv as A, b.state_abv as B
	from allzips a, allzips b
	where a.zip = b.zip and a.state_abv != b.state_abv
)
where mod(n,2) = 0;

exit;
