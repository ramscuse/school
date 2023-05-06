create table ramscuse_students (name varchar(255), id int, gpa double);

show create table ramscuse_students;

insert into ramscuse_students values ('Aaa', 800000001, 2.0+(RAND()*2.0));
insert into ramscuse_students values ('Bbb', 800000002, 2.0+(RAND()*2.0));
insert into ramscuse_students values ('Ccc', 800000003, 2.0+(RAND()*2.0));
insert into ramscuse_students values ('Ddd', 800000004, 2.0+(RAND()*2.0));
insert into ramscuse_students values ('Eee', 800000005, 2.0+(RAND()*2.0));
insert into ramscuse_students values ('Fff', 800000006, 2.0+(RAND()*2.0));
insert into ramscuse_students values ('Ggg', 800000007, 2.0+(RAND()*2.0));
insert into ramscuse_students values ('Hhh', 800000008, 2.0+(RAND()*2.0));
insert into ramscuse_students values ('Iii', 800000009, 2.0+(RAND()*2.0));
insert into ramscuse_students values ('Jjj', 800000010, 2.0+(RAND()*2.0));
insert into ramscuse_students values ('Kkk', 800000011, 2.0+(RAND()*2.0));
insert into ramscuse_students values ('Lll', 800000012, 2.0+(RAND()*2.0));
insert into ramscuse_students values ('Mmm', 800000013, 2.0+(RAND()*2.0));
insert into ramscuse_students values ('Nnn', 800000014, 2.0+(RAND()*2.0));
insert into ramscuse_students values ('Ooo', 800000015, 2.0+(RAND()*2.0));
insert into ramscuse_students values ('Ppp', 800000016, 2.0+(RAND()*2.0));
insert into ramscuse_students values ('Qqq', 800000017, 2.0+(RAND()*2.0));
insert into ramscuse_students values ('Rrr', 800000018, 2.0+(RAND()*2.0));
insert into ramscuse_students values ('Sss', 800000019, 2.0+(RAND()*2.0));
insert into ramscuse_students values ('Ttt', 800000020, 2.0+(RAND()*2.0));
insert into ramscuse_students values ('Uuu', 800000021, 2.0+(RAND()*2.0));
insert into ramscuse_students values ('Vvv', 800000022, 2.0+(RAND()*2.0));
insert into ramscuse_students values ('Www', 800000023, 2.0+(RAND()*2.0));
insert into ramscuse_students values ('Xxx', 800000024, 2.0+(RAND()*2.0));
insert into ramscuse_students values ('Yyy', 800000025, 2.0+(RAND()*2.0));
insert into ramscuse_students values ('Zzz', 800000026, 2.0+(RAND()*2.0));

select * from ramscuse_students;

create table ramscuse_classes (department_code varchar(255), course_number int, credits int);

insert into ramscuse_classes values ('CS', 165, 4);
insert into ramscuse_classes values ('CS', 220, 4);
insert into ramscuse_classes values ('CS', 270, 4);
insert into ramscuse_classes values ('CS', 253, 4);
insert into ramscuse_classes values ('CS', 370, 3);
insert into ramscuse_classes values ('CS', 356, 3);
insert into ramscuse_classes values ('CS', 314, 3);
insert into ramscuse_classes values ('CS', 312, 3);
insert into ramscuse_classes values ('CS', 320, 4);

select * from ramscuse_classes;

update ramscuse_classes set department_code = 'CT' where course_number = 312;
update ramscuse_classes set course_number = 310 where department_code = 'CT';

select * from ramscuse_classes;

create table ramscuse_enrollments (id int, department_code varchar(255), course_number int, semester ENUM('FA19', 'SP20', 'FA20', 'SP21', 'FA21', 'SU22', 'FA22', 'SP23'));

insert into ramscuse_enrollments values (800000001, 'CT', 310, 'SP23');
insert into ramscuse_enrollments values (800000001, 'CS', 220, 'SP23');
insert into ramscuse_enrollments values (800000001, 'CS', 270, 'SP23');
insert into ramscuse_enrollments values (800000001, 'CS', 356, 'SP23');
insert into ramscuse_enrollments values (800000002, 'CS', 320, 'SP23');
insert into ramscuse_enrollments values (800000002, 'CS', 220, 'SP23');
insert into ramscuse_enrollments values (800000002, 'CS', 270, 'SP23');
insert into ramscuse_enrollments values (800000002, 'CS', 356, 'SP23');
insert into ramscuse_enrollments values (800000003, 'CS', 320, 'SP23');
insert into ramscuse_enrollments values (800000003, 'CS', 220, 'SP23');
insert into ramscuse_enrollments values (800000003, 'CS', 270, 'SP23');
insert into ramscuse_enrollments values (800000003, 'CS', 356, 'SP23');
insert into ramscuse_enrollments values (800000004, 'CS', 320, 'SP23');
insert into ramscuse_enrollments values (800000004, 'CS', 220, 'SP23');
insert into ramscuse_enrollments values (800000004, 'CS', 270, 'SP23');
insert into ramscuse_enrollments values (800000004, 'CS', 356, 'SP23');
insert into ramscuse_enrollments values (800000005, 'CS', 320, 'SP23');
insert into ramscuse_enrollments values (800000005, 'CS', 220, 'SP23');
insert into ramscuse_enrollments values (800000005, 'CS', 270, 'SP23');
insert into ramscuse_enrollments values (800000005, 'CS', 356, 'SP23');
insert into ramscuse_enrollments values (800000006, 'CS', 320, 'SP23');
insert into ramscuse_enrollments values (800000006, 'CS', 165, 'SP23');
insert into ramscuse_enrollments values (800000006, 'CS', 270, 'SP23');
insert into ramscuse_enrollments values (800000006, 'CS', 356, 'SP23');
insert into ramscuse_enrollments values (800000007, 'CS', 320, 'SP23');
insert into ramscuse_enrollments values (800000007, 'CT', 310, 'SP23');
insert into ramscuse_enrollments values (800000007, 'CS', 270, 'SP23');
insert into ramscuse_enrollments values (800000007, 'CS', 356, 'SP23');
insert into ramscuse_enrollments values (800000008, 'CS', 320, 'SP23');
insert into ramscuse_enrollments values (800000008, 'CS', 220, 'SP23');
insert into ramscuse_enrollments values (800000008, 'CS', 270, 'SP23');
insert into ramscuse_enrollments values (800000008, 'CS', 356, 'SP23');
insert into ramscuse_enrollments values (800000009, 'CS', 165, 'SP23');
insert into ramscuse_enrollments values (800000009, 'CS', 220, 'SP23');
insert into ramscuse_enrollments values (800000009, 'CS', 270, 'SP23');
insert into ramscuse_enrollments values (800000009, 'CS', 370, 'SP23');
insert into ramscuse_enrollments values (800000010, 'CS', 320, 'SP23');
insert into ramscuse_enrollments values (800000010, 'CS', 220, 'SP23');
insert into ramscuse_enrollments values (800000010, 'CS', 270, 'SP23');
insert into ramscuse_enrollments values (800000010, 'CS', 356, 'SP23');
insert into ramscuse_enrollments values (800000011, 'CS', 320, 'SP23');
insert into ramscuse_enrollments values (800000011, 'CS', 220, 'SP23');
insert into ramscuse_enrollments values (800000011, 'CS', 270, 'SP23');
insert into ramscuse_enrollments values (800000011, 'CS', 356, 'SP23');
insert into ramscuse_enrollments values (800000012, 'CS', 165, 'SP23');
insert into ramscuse_enrollments values (800000012, 'CS', 220, 'SP23');
insert into ramscuse_enrollments values (800000012, 'CS', 270, 'SP23');
insert into ramscuse_enrollments values (800000012, 'CS', 356, 'SP23');
insert into ramscuse_enrollments values (800000013, 'CS', 320, 'SP23');
insert into ramscuse_enrollments values (800000013, 'CS', 220, 'SP23');
insert into ramscuse_enrollments values (800000013, 'CT', 310, 'SP23');
insert into ramscuse_enrollments values (800000013, 'CS', 370, 'SP23');
insert into ramscuse_enrollments values (800000014, 'CS', 320, 'SP23');
insert into ramscuse_enrollments values (800000014, 'CS', 220, 'SP23');
insert into ramscuse_enrollments values (800000014, 'CS', 270, 'SP23');
insert into ramscuse_enrollments values (800000014, 'CS', 256, 'SP23');
insert into ramscuse_enrollments values (800000015, 'CS', 320, 'SP23');
insert into ramscuse_enrollments values (800000015, 'CS', 220, 'SP23');
insert into ramscuse_enrollments values (800000015, 'CS', 270, 'SP23');
insert into ramscuse_enrollments values (800000015, 'CS', 356, 'SP23');
insert into ramscuse_enrollments values (800000016, 'CS', 320, 'SP23');
insert into ramscuse_enrollments values (800000016, 'CS', 220, 'SP23');
insert into ramscuse_enrollments values (800000016, 'CS', 270, 'SP23');
insert into ramscuse_enrollments values (800000016, 'CS', 356, 'SP23');
insert into ramscuse_enrollments values (800000017, 'CS', 320, 'SP23');
insert into ramscuse_enrollments values (800000017, 'CS', 220, 'SP23');
insert into ramscuse_enrollments values (800000017, 'CS', 270, 'SP23');
insert into ramscuse_enrollments values (800000017, 'CS', 356, 'SP23');
insert into ramscuse_enrollments values (800000018, 'CS', 320, 'SP23');
insert into ramscuse_enrollments values (800000018, 'CS', 370, 'SP23');
insert into ramscuse_enrollments values (800000018, 'CS', 270, 'SP23');
insert into ramscuse_enrollments values (800000018, 'CS', 165, 'SP23');
insert into ramscuse_enrollments values (800000019, 'CS', 320, 'SP23');
insert into ramscuse_enrollments values (800000019, 'CS', 220, 'SP23');
insert into ramscuse_enrollments values (800000019, 'CT', 310, 'SP23');
insert into ramscuse_enrollments values (800000019, 'CS', 356, 'SP23');
insert into ramscuse_enrollments values (800000020, 'CT', 310, 'SP23');
insert into ramscuse_enrollments values (800000020, 'CS', 220, 'SP23');
insert into ramscuse_enrollments values (800000020, 'CS', 270, 'SP23');
insert into ramscuse_enrollments values (800000020, 'CS', 356, 'SP23');
insert into ramscuse_enrollments values (800000021, 'CS', 320, 'SP23');
insert into ramscuse_enrollments values (800000021, 'CS', 220, 'SP23');
insert into ramscuse_enrollments values (800000021, 'CS', 270, 'SP23');
insert into ramscuse_enrollments values (800000021, 'CS', 356, 'SP23');
insert into ramscuse_enrollments values (800000022, 'CS', 320, 'SP23');
insert into ramscuse_enrollments values (800000022, 'CS', 220, 'SP23');
insert into ramscuse_enrollments values (800000022, 'CS', 270, 'SP23');
insert into ramscuse_enrollments values (800000022, 'CS', 356, 'SP23');
insert into ramscuse_enrollments values (800000023, 'CS', 320, 'SP23');
insert into ramscuse_enrollments values (800000023, 'CS', 220, 'SP23');
insert into ramscuse_enrollments values (800000023, 'CS', 270, 'SP23');
insert into ramscuse_enrollments values (800000023, 'CS', 356, 'SP23');
insert into ramscuse_enrollments values (800000024, 'CS', 320, 'SP23');
insert into ramscuse_enrollments values (800000024, 'CS', 220, 'SP23');
insert into ramscuse_enrollments values (800000024, 'CS', 270, 'SP23');
insert into ramscuse_enrollments values (800000024, 'CT', 310, 'SP23');
insert into ramscuse_enrollments values (800000025, 'CS', 370, 'SP23');
insert into ramscuse_enrollments values (800000025, 'CS', 220, 'SP23');
insert into ramscuse_enrollments values (800000025, 'CS', 165, 'SP23');
insert into ramscuse_enrollments values (800000025, 'CS', 356, 'SP23');
insert into ramscuse_enrollments values (800000026, 'CS', 320, 'SP23');
insert into ramscuse_enrollments values (800000026, 'CS', 220, 'SP23');
insert into ramscuse_enrollments values (800000026, 'CT', 310, 'SP23');
insert into ramscuse_enrollments values (800000026, 'CS', 356, 'SP23');

select * from ramscuse_enrollments where department_code = 'CT' and course_number = 310;

