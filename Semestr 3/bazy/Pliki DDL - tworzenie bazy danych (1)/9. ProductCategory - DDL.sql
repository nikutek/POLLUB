--------------------------------------------------------
--  DDL for Table PRODUCTCATEGORY
--------------------------------------------------------

  CREATE TABLE "PRODUCTCATEGORY" 
   (	"PRODUCTCATEGORYKEY" NUMBER(2,0), 
	"PRODUCTCATEGORYNAME" VARCHAR2(30)
   );
--------------------------------------------------------
--  DDL for Index PRODUCTCATEGORY_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "PRODUCTCATEGORY_PK" ON "PRODUCTCATEGORY" ("PRODUCTCATEGORYKEY");
--------------------------------------------------------
--  DDL for Index PRODUCTCATEGORY_NAME_UQ
--------------------------------------------------------

  CREATE UNIQUE INDEX "PRODUCTCATEGORY_NAME_UQ" ON "PRODUCTCATEGORY" ("PRODUCTCATEGORYNAME");
--------------------------------------------------------
--  Constraints for Table PRODUCTCATEGORY
--------------------------------------------------------

  ALTER TABLE "PRODUCTCATEGORY" ADD CONSTRAINT "PRODUCTCATEGORY_NAME_UQ" UNIQUE ("PRODUCTCATEGORYNAME") ENABLE;
 
  ALTER TABLE "PRODUCTCATEGORY" ADD CONSTRAINT "PRODUCTCATEGORY_PK" PRIMARY KEY ("PRODUCTCATEGORYKEY") ENABLE;
 
  ALTER TABLE "PRODUCTCATEGORY" MODIFY ("PRODUCTCATEGORYKEY" NOT NULL ENABLE);
 
  ALTER TABLE "PRODUCTCATEGORY" MODIFY ("PRODUCTCATEGORYNAME" NOT NULL ENABLE);
