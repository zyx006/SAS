create database stuAdminSystem;

use stuAdminSystem;

create table student(
	id nvarchar(10) primary key,
	name nvarchar(15) not null,
	sex nvarchar(5) not null,
	stuClass nvarchar(20) not null,
	status nvarchar(10) not null
);

create table course(
	id nvarchar(10) primary key,
	name nvarchar(50) not null
);

create table grade(
	stuId nvarchar(10),
	courseId nvarchar(10),
	graded decimal(5,2) not null,
	primary key(stuId,courseId)
);



insert into student 
values
('1','����','��','���12004','�ڶ�'),
('2','����','Ů','���12004','�ڶ�'),
('3','����','Ů','�ƿ�12003','�ڶ�'),
('4','����','Ů','������12001','�ڶ�'),
('5','�����','��','�ƿ�12003','�ڶ�'),
('6','κ��˰','��','���12004','�ڶ�'),
('7','����','Ů','�ƿ�12003','�ڶ�'),
('8','����','��','���12004','�ڶ�');

insert into course
values
('C001','����'),
('C002','��ѧӢ��'),
('C003','���Դ���'),
('C004','��ѧ����'),
('C005','C����'),
('C006','����');

insert into grade
values
('1','C001',95),
('1','C002',90),
('1','C005',97),
('2','C006',75),
('2','C001',90),
('3','C005',76),
('4','C003',75),
('5','C001',78),
('8','C001',98);