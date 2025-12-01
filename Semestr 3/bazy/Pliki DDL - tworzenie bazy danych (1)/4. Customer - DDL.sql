--------------------------------------------------------
--  DDL for Table CUSTOMER
--------------------------------------------------------

  CREATE TABLE "CUSTOMER" 
   (	"CUSTOMERKEY" NUMBER(10,0), 
	"FIRSTNAME" VARCHAR2(15), 
	"LASTNAME" VARCHAR2(20), 
	"CITYKEY" NUMBER(3,0)
   );
--------------------------------------------------------
--  DDL for Index CUSTOMER_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "CUSTOMER_PK" ON "CUSTOMER" ("CUSTOMERKEY");
--------------------------------------------------------
--------------------------------------------------------
--  Constraints for Table CUSTOMER
--------------------------------------------------------

  ALTER TABLE "CUSTOMER" ADD CONSTRAINT "CUSTOMER_PK" PRIMARY KEY ("CUSTOMERKEY") ENABLE;
 
  ALTER TABLE "CUSTOMER" MODIFY ("CUSTOMERKEY" NOT NULL ENABLE);
 
  ALTER TABLE "CUSTOMER" MODIFY ("FIRSTNAME" NOT NULL ENABLE);
 
  ALTER TABLE "CUSTOMER" MODIFY ("LASTNAME" NOT NULL ENABLE);
 
  ALTER TABLE "CUSTOMER" MODIFY ("CITYKEY" NOT NULL ENABLE);
--------------------------------------------------------
--  Ref Constraints for Table CUSTOMER
--------------------------------------------------------

  ALTER TABLE "CUSTOMER" ADD CONSTRAINT "CUSTOMER_CITY_FK" FOREIGN KEY ("CITYKEY")
	  REFERENCES "CITY" ("CITYKEY") ENABLE;
