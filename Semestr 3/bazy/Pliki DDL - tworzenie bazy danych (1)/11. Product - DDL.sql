--------------------------------------------------------
--  DDL for Table PRODUCT
--------------------------------------------------------

  CREATE TABLE "PRODUCT" 
   (	"PRODUCTKEY" NUMBER(5,0), 
	"PRODUCTCODE" VARCHAR2(15), 
	"PRODUCTNAME" VARCHAR2(35), 
	"PRODUCTSUBCATEGORYKEY" NUMBER(3,0)
   );
--------------------------------------------------------
--  DDL for Index PRODUCT_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "PRODUCT_PK" ON "PRODUCT" ("PRODUCTKEY");
--------------------------------------------------------
--  DDL for Index PRODUCT_CODE_UQ
--------------------------------------------------------

  CREATE UNIQUE INDEX "PRODUCT_CODE_UQ" ON "PRODUCT" ("PRODUCTCODE");
--------------------------------------------------------
--  DDL for Index PRODUCT_NAME_UQ
--------------------------------------------------------

  CREATE UNIQUE INDEX "PRODUCT_NAME_UQ" ON "PRODUCT" ("PRODUCTNAME");
--------------------------------------------------------
--  Constraints for Table PRODUCT
--------------------------------------------------------

  ALTER TABLE "PRODUCT" ADD CONSTRAINT "PRODUCT_CODE_UQ" UNIQUE ("PRODUCTCODE") ENABLE;
 
  ALTER TABLE "PRODUCT" ADD CONSTRAINT "PRODUCT_NAME_UQ" UNIQUE ("PRODUCTNAME") ENABLE;
 
  ALTER TABLE "PRODUCT" ADD CONSTRAINT "PRODUCT_PK" PRIMARY KEY ("PRODUCTKEY") ENABLE;
 
  ALTER TABLE "PRODUCT" MODIFY ("PRODUCTKEY" NOT NULL ENABLE);
 
  ALTER TABLE "PRODUCT" MODIFY ("PRODUCTNAME" NOT NULL ENABLE);
 
  ALTER TABLE "PRODUCT" MODIFY ("PRODUCTSUBCATEGORYKEY" NOT NULL ENABLE);
 
  ALTER TABLE "PRODUCT" MODIFY ("PRODUCTCODE" NOT NULL ENABLE);
--------------------------------------------------------
--  Ref Constraints for Table PRODUCT
--------------------------------------------------------

  ALTER TABLE "PRODUCT" ADD CONSTRAINT "PRODUCT_SUBCATEGORY_FK" FOREIGN KEY ("PRODUCTSUBCATEGORYKEY")
	  REFERENCES "PRODUCTSUBCATEGORY" ("PRODUCTSUBCATEGORYKEY") ENABLE;
