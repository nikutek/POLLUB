--------------------------------------------------------
--  DDL for Table ORDERSTATUS
--------------------------------------------------------

  CREATE TABLE "ORDERSTATUS" 
   (	"ORDERSTATUSKEY" NUMBER(1,0), 
	"ORDERSTATUSNAME" VARCHAR2(20)
   );
--------------------------------------------------------
--  DDL for Index ORDERSTATUS_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "ORDERSTATUS_PK" ON "ORDERSTATUS" ("ORDERSTATUSKEY");
--------------------------------------------------------
--  DDL for Index ORDERSTATUS_NAME_UN
--------------------------------------------------------

  CREATE UNIQUE INDEX "ORDERSTATUS_NAME_UN" ON "ORDERSTATUS" ("ORDERSTATUSNAME");
--------------------------------------------------------
--  Constraints for Table ORDERSTATUS
--------------------------------------------------------

  ALTER TABLE "ORDERSTATUS" ADD CONSTRAINT "ORDERSTATUS_NME_UN" UNIQUE ("ORDERSTATUSNAME") ENABLE;
 
  ALTER TABLE "ORDERSTATUS" ADD CONSTRAINT "ORDERSTATUS_PK" PRIMARY KEY ("ORDERSTATUSKEY") ENABLE;
 
  ALTER TABLE "ORDERSTATUS" MODIFY ("ORDERSTATUSKEY" NOT NULL ENABLE);
 
  ALTER TABLE "ORDERSTATUS" MODIFY ("ORDERSTATUSNAME" NOT NULL ENABLE);
