--------------------------------------------------------
--  DDL for Table CITY
--------------------------------------------------------

  CREATE TABLE "CITY" 
   (	"CITYKEY" NUMBER(3,0), 
	"CITYNAME" VARCHAR2(30), 
	"COUNTRYKEY" NUMBER(2,0)
   );
--------------------------------------------------------
--  DDL for Index CITY_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "CITY_PK" ON "CITY" ("CITYKEY");
--------------------------------------------------------
--  Constraints for Table CITY
--------------------------------------------------------

  ALTER TABLE "CITY" ADD CONSTRAINT "CITY_PK" PRIMARY KEY ("CITYKEY") ENABLE;
 
  ALTER TABLE "CITY" MODIFY ("CITYKEY" NOT NULL ENABLE);
 
  ALTER TABLE "CITY" MODIFY ("CITYNAME" NOT NULL ENABLE);
 
  ALTER TABLE "CITY" MODIFY ("COUNTRYKEY" NOT NULL ENABLE);
--------------------------------------------------------
--  Ref Constraints for Table CITY
--------------------------------------------------------

  ALTER TABLE "CITY" ADD CONSTRAINT "CITY_COUNTRY_FK" FOREIGN KEY ("COUNTRYKEY")
	  REFERENCES "COUNTRY" ("COUNTRYKEY") ENABLE;
