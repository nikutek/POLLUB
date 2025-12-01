--------------------------------------------------------
--  DDL for Table COUNTRY
--------------------------------------------------------

  CREATE TABLE "COUNTRY" 
   (	"COUNTRYKEY" NUMBER(2,0), 
	"COUNTRYNAME" VARCHAR2(15), 
	"COUNTRYCODE" CHAR(2), 
	"SALESTERRITORYKEY" NUMBER(3,0)
   );
--------------------------------------------------------
--  DDL for Index COUNTRY_NAME_UQ
--------------------------------------------------------

  CREATE INDEX "COUNTRY_NAME_UQ" ON "COUNTRY" ("COUNTRYNAME");
--------------------------------------------------------
--  DDL for Index COUNTRY_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "COUNTRY_PK" ON "COUNTRY" ("COUNTRYKEY");
--------------------------------------------------------
--  Constraints for Table COUNTRY
--------------------------------------------------------

  ALTER TABLE "COUNTRY" ADD CONSTRAINT "COUNTRY_NAME_UN" UNIQUE ("COUNTRYNAME") ENABLE;
 
  ALTER TABLE "COUNTRY" ADD CONSTRAINT "COUNTRY_PK" PRIMARY KEY ("COUNTRYKEY") ENABLE;
 
  ALTER TABLE "COUNTRY" MODIFY ("COUNTRYKEY" NOT NULL ENABLE);
 
  ALTER TABLE "COUNTRY" MODIFY ("COUNTRYNAME" NOT NULL ENABLE);
 
  ALTER TABLE "COUNTRY" MODIFY ("COUNTRYCODE" NOT NULL ENABLE);
 
  ALTER TABLE "COUNTRY" MODIFY ("SALESTERRITORYKEY" NOT NULL ENABLE);
--------------------------------------------------------
--  Ref Constraints for Table COUNTRY
--------------------------------------------------------

  ALTER TABLE "COUNTRY" ADD CONSTRAINT "COUNTRY_SALESTERRITORY_FK" FOREIGN KEY ("SALESTERRITORYKEY")
	  REFERENCES "SALESTERRITORY" ("SALESTERRITORYKEY") ENABLE;
