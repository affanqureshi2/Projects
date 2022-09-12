/*
SQLyog Ultimate v10.00 Beta1
MySQL - 5.7.31 : Database - teacher
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
CREATE DATABASE /*!32312 IF NOT EXISTS*/`teacher` /*!40100 DEFAULT CHARACTER SET latin1 */;

USE `teacher`;

/*Table structure for table `class` */

DROP TABLE IF EXISTS `class`;

CREATE TABLE `class` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `value` int(10) NOT NULL,
  `name` varchar(50) NOT NULL,
  `created_at` datetime DEFAULT NULL,
  `updated_at` datetime DEFAULT NULL,
  `deleted_at` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;

/*Data for the table `class` */

insert  into `class`(`id`,`value`,`name`,`created_at`,`updated_at`,`deleted_at`) values (1,1,'I','2022-09-11 11:21:54',NULL,NULL);
insert  into `class`(`id`,`value`,`name`,`created_at`,`updated_at`,`deleted_at`) values (2,2,'II','2022-09-11 11:22:01',NULL,NULL);
insert  into `class`(`id`,`value`,`name`,`created_at`,`updated_at`,`deleted_at`) values (3,3,'III','2022-09-11 11:22:01',NULL,NULL);

/*Table structure for table `period` */

DROP TABLE IF EXISTS `period`;

CREATE TABLE `period` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `teacher_id` int(11) DEFAULT NULL,
  `class_id` int(11) DEFAULT NULL,
  `subject_id` int(11) DEFAULT NULL,
  `start_time` time DEFAULT NULL,
  `duration` int(11) DEFAULT NULL COMMENT 'in minutes',
  `end_time` time DEFAULT NULL,
  `created_at` datetime DEFAULT NULL,
  `updated_at` datetime DEFAULT NULL,
  `deleted_at` datetime DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_teacher_period` (`teacher_id`),
  KEY `fk_class_period` (`class_id`),
  KEY `fk_subject_period` (`subject_id`),
  CONSTRAINT `fk_class_period` FOREIGN KEY (`class_id`) REFERENCES `class` (`id`),
  CONSTRAINT `fk_subject_period` FOREIGN KEY (`subject_id`) REFERENCES `subject` (`id`),
  CONSTRAINT `fk_teacher_period` FOREIGN KEY (`teacher_id`) REFERENCES `teacher` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=latin1;

/*Data for the table `period` */

insert  into `period`(`id`,`teacher_id`,`class_id`,`subject_id`,`start_time`,`duration`,`end_time`,`created_at`,`updated_at`,`deleted_at`) values (1,1,1,1,'10:00:00',45,'10:45:00','2022-09-11 11:26:39',NULL,NULL);
insert  into `period`(`id`,`teacher_id`,`class_id`,`subject_id`,`start_time`,`duration`,`end_time`,`created_at`,`updated_at`,`deleted_at`) values (2,1,1,2,'10:45:00',45,'11:30:00','2022-09-11 11:27:06',NULL,NULL);
insert  into `period`(`id`,`teacher_id`,`class_id`,`subject_id`,`start_time`,`duration`,`end_time`,`created_at`,`updated_at`,`deleted_at`) values (4,1,1,3,'11:30:00',45,'12:30:00','2022-09-11 06:34:41','2022-09-11 06:34:41',NULL);
insert  into `period`(`id`,`teacher_id`,`class_id`,`subject_id`,`start_time`,`duration`,`end_time`,`created_at`,`updated_at`,`deleted_at`) values (5,1,1,3,'11:30:00',NULL,'12:30:00','2022-09-12 15:27:21','2022-09-12 15:27:21',NULL);
insert  into `period`(`id`,`teacher_id`,`class_id`,`subject_id`,`start_time`,`duration`,`end_time`,`created_at`,`updated_at`,`deleted_at`) values (6,1,1,1,'20:28:00',NULL,'12:28:00','2022-09-12 15:29:16','2022-09-12 15:29:16',NULL);
insert  into `period`(`id`,`teacher_id`,`class_id`,`subject_id`,`start_time`,`duration`,`end_time`,`created_at`,`updated_at`,`deleted_at`) values (7,2,1,1,'20:28:00',NULL,'12:28:00','2022-09-12 15:29:38','2022-09-12 15:29:38',NULL);
insert  into `period`(`id`,`teacher_id`,`class_id`,`subject_id`,`start_time`,`duration`,`end_time`,`created_at`,`updated_at`,`deleted_at`) values (8,2,2,1,'20:28:00',NULL,'16:28:00','2022-09-12 15:29:46','2022-09-12 15:29:46',NULL);
insert  into `period`(`id`,`teacher_id`,`class_id`,`subject_id`,`start_time`,`duration`,`end_time`,`created_at`,`updated_at`,`deleted_at`) values (9,2,3,2,'22:31:00',-10,'12:31:00','2022-09-12 15:31:11','2022-09-12 15:31:11',NULL);
insert  into `period`(`id`,`teacher_id`,`class_id`,`subject_id`,`start_time`,`duration`,`end_time`,`created_at`,`updated_at`,`deleted_at`) values (10,3,2,2,'13:00:00',1,'14:00:00','2022-09-12 15:31:48','2022-09-12 15:31:48',NULL);
insert  into `period`(`id`,`teacher_id`,`class_id`,`subject_id`,`start_time`,`duration`,`end_time`,`created_at`,`updated_at`,`deleted_at`) values (11,4,2,3,'13:00:00',60,'14:00:00','2022-09-12 15:32:53','2022-09-12 15:32:53',NULL);

/*Table structure for table `subject` */

DROP TABLE IF EXISTS `subject`;

CREATE TABLE `subject` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `name` varchar(100) NOT NULL,
  `description` varchar(255) DEFAULT NULL,
  `created_at` datetime DEFAULT NULL,
  `updated_at` datetime DEFAULT NULL,
  `deleted_at` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;

/*Data for the table `subject` */

insert  into `subject`(`id`,`name`,`description`,`created_at`,`updated_at`,`deleted_at`) values (1,'Science','Science having physics,chemistry,biology','2022-09-11 11:22:44',NULL,NULL);
insert  into `subject`(`id`,`name`,`description`,`created_at`,`updated_at`,`deleted_at`) values (2,'Maths','Mathematics','2022-09-11 11:22:54',NULL,NULL);
insert  into `subject`(`id`,`name`,`description`,`created_at`,`updated_at`,`deleted_at`) values (3,'English','English Literatures','2022-09-11 11:23:11',NULL,NULL);

/*Table structure for table `teacher` */

DROP TABLE IF EXISTS `teacher`;

CREATE TABLE `teacher` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(50) NOT NULL,
  `qualification` varchar(50) NOT NULL,
  `start_time` time NOT NULL COMMENT 'available time',
  `end_time` time NOT NULL,
  `created_at` datetime DEFAULT NULL,
  `updated_at` datetime DEFAULT NULL,
  `deleted_at` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=latin1;

/*Data for the table `teacher` */

insert  into `teacher`(`id`,`name`,`qualification`,`start_time`,`end_time`,`created_at`,`updated_at`,`deleted_at`) values (1,'Zeeshan','MSc','10:45:00','11:45:00',NULL,NULL,NULL);
insert  into `teacher`(`id`,`name`,`qualification`,`start_time`,`end_time`,`created_at`,`updated_at`,`deleted_at`) values (2,'Affan','Bsc','12:00:00','13:00:00',NULL,NULL,NULL);
insert  into `teacher`(`id`,`name`,`qualification`,`start_time`,`end_time`,`created_at`,`updated_at`,`deleted_at`) values (3,'Arslan','BSc Civil Engineering','10:00:00','11:45:00','2022-09-10 17:53:11','2022-09-10 17:53:11',NULL);
insert  into `teacher`(`id`,`name`,`qualification`,`start_time`,`end_time`,`created_at`,`updated_at`,`deleted_at`) values (4,'Arslan','BSc Civil Engineering','10:00:00','11:45:00','2022-09-11 08:11:56','2022-09-11 08:11:56',NULL);
insert  into `teacher`(`id`,`name`,`qualification`,`start_time`,`end_time`,`created_at`,`updated_at`,`deleted_at`) values (5,'Amir Arslan','PHD Computer Engineering','12:00:00','13:00:00','2022-09-11 08:14:36','2022-09-11 08:14:36',NULL);
insert  into `teacher`(`id`,`name`,`qualification`,`start_time`,`end_time`,`created_at`,`updated_at`,`deleted_at`) values (6,'Affan','Msc','13:59:00','15:00:00','2022-09-11 10:46:04','2022-09-11 10:46:04',NULL);
insert  into `teacher`(`id`,`name`,`qualification`,`start_time`,`end_time`,`created_at`,`updated_at`,`deleted_at`) values (7,'AVBC','asdfdsa','02:00:00','01:01:00','2022-09-12 14:43:50','2022-09-12 14:43:50',NULL);
insert  into `teacher`(`id`,`name`,`qualification`,`start_time`,`end_time`,`created_at`,`updated_at`,`deleted_at`) values (8,'afds','adsf','01:00:00','01:00:00','2022-09-12 14:57:24','2022-09-12 14:57:24',NULL);
insert  into `teacher`(`id`,`name`,`qualification`,`start_time`,`end_time`,`created_at`,`updated_at`,`deleted_at`) values (9,'fadsfasd','dasfafds','19:59:00','12:59:00','2022-09-12 14:59:36','2022-09-12 14:59:36',NULL);
insert  into `teacher`(`id`,`name`,`qualification`,`start_time`,`end_time`,`created_at`,`updated_at`,`deleted_at`) values (10,'afd','afds','20:01:00','12:01:00','2022-09-12 15:01:15','2022-09-12 15:01:15',NULL);

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
