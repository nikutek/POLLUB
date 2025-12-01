--------------------------------------------------------
--  DDL for Table SALESTERRITORY
--------------------------------------------------------

  CREATE TABLE "SALESTERRITORY"
   (	"SALESTERRITORYKEY" NUMBER(3,0),
	"SALESTERRITORYNAME" VARCHAR2(25)
   );
--------------------------------------------------------
--  DDL for Index SALESTNAME_UQ
--------------------------------------------------------

  CREATE UNIQUE INDEX "SALESTNAME_UQ" ON "SALESTERRITORY" ("SALESTERRITORYNAME");
--------------------------------------------------------
--  DDL for Index SALESTERRITORY_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "SALESTERRITORY_PK" ON "SALESTERRITORY" ("SALESTERRITORYKEY");
--------------------------------------------------------
--  Constraints for Table SALESTERRITORY
--------------------------------------------------------

  ALTER TABLE "SALESTERRITORY" ADD CONSTRAINT "SALESTERRITORY_NAME_UN" UNIQUE ("SALESTERRITORYNAME") ENABLE;

  ALTER TABLE "SALESTERRITORY" ADD CONSTRAINT "SALESTERRITORY_PK" PRIMARY KEY ("SALESTERRITORYKEY") ENABLE;

  ALTER TABLE "SALESTERRITORY" MODIFY ("SALESTERRITORYKEY" NOT NULL ENABLE);

  ALTER TABLE "SALESTERRITORY" MODIFY ("SALESTERRITORYNAME" NOT NULL ENABLE);
