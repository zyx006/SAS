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
('1','张三','男','软件12004','在读'),
('2','李四','女','软件12004','在读'),
('3','王五','女','计科12003','在读'),
('4','赵六','女','物联网12001','在读'),
('5','李恩情','男','计科12003','在读'),
('6','魏抵税','男','软件12004','在读'),
('7','张三','女','计科12003','在读'),
('8','李六','男','软件12004','在读');

insert into course
values
('C001','高数'),
('C002','大学英语'),
('C003','线性代数'),
('C004','大学物理'),
('C005','C语言'),
('C006','体育');

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