-- gp3 project

drop sequence user_seq;
create sequence user_seq start with 1;

create or replace trigger user_t
before insert on users
for each row

begin
	select user_seq.NEXTVAL
	into :new.user_id
	from dual;
end;
/

exit;
