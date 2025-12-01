--------------------------------------------------------
--  DDL for Table PRODUCTSUBCATEGORY
--------------------------------------------------------

  CREATE TABLE "PRODUCTSUBCATEGORY" 
   (	"PRODUCTSUBCATEGORYKEY" NUMBER(3,0), 
	"PRODUCTSUBCATEGORYNAME" VARCHAR2(40), 
	"PRODUCTCATEGORYKEY" NUMBER(2,0)
   );
--------------------------------------------------------
--  DDL for Index PRODUCTSUBCATEGORY_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "PRODUCTSUBCATEGORY_PK" ON "PRODUCTSUBCATEGORY" ("PRODUCTSUBCATEGORYKEY");
--------------------------------------------------------
--  DDL for Index PRODUCTSUBCATEGORY_NAME_UQ
--------------------------------------------------------

  CREATE UNIQUE INDEX "PRODUCTSUBCATEGORY_NAME_UQ" ON "PRODUCTSUBCATEGORY" ("PRODUCTSUBCATEGORYNAME");
--------------------------------------------------------
--------------------------------------------------------
--  Constraints for Table PRODUCTSUBCATEGORY
--------------------------------------------------------

  ALTER TABLE "PRODUCTSUBCATEGORY" ADD CONSTRAINT "PRODUCTSUBCATEGORY_NAME_UQ" UNIQUE ("PRODUCTSUBCATEGORYNAME") ENABLE;
 
  ALTER TABLE "PRODUCTSUBCATEGORY" ADD CONSTRAINT "PRODUCTSUBCATEGORY_PK" PRIMARY KEY ("PRODUCTSUBCATEGORYKEY") ENABLE;
 
  ALTER TABLE "PRODUCTSUBCATEGORY" MODIFY ("PRODUCTSUBCATEGORYKEY" NOT NULL ENABLE);
 
  ALTER TABLE "PRODUCTSUBCATEGORY" MODIFY ("PRODUCTSUBCATEGORYNAME" NOT NULL ENABLE);
 
  ALTER TABLE "PRODUCTSUBCATEGORY" MODIFY ("PRODUCTCATEGORYKEY" NOT NULL ENABLE);
--------------------------------------------------------
--  Ref Constraints for Table PRODUCTSUBCATEGORY
--------------------------------------------------------

  ALTER TABLE "PRODUCTSUBCATEGORY" ADD CONSTRAINT "PRODUCTSUBCAT_CAT_FK" FOREIGN KEY ("PRODUCTCATEGORYKEY")
	  REFERENCES "PRODUCTCATEGORY" ("PRODUCTCATEGORYKEY") ENABLE;
