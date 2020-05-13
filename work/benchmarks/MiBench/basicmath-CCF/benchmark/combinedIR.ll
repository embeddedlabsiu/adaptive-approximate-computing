; ModuleID = 'temp.bc'
source_filename = "llvm-link"
target datalayout = "e-m:e-p:32:32-i64:64-v128:64:128-a:0:32-n32-S64"
target triple = "armv7--linux-eabi"

%struct._IO_FILE = type { i32, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, %struct._IO_marker*, %struct._IO_FILE*, i32, i32, i32, i16, i8, [1 x i8], i8*, i64, i8*, i8*, i8*, i8*, i32, i32, [40 x i8] }
%struct._IO_marker = type { %struct._IO_marker*, %struct._IO_FILE*, i32 }
%union.pthread_attr_t = type { i32, [32 x i8] }

@str = private unnamed_addr constant [28 x i8] c"Starting Addition Benchmark\00"
@.str.1 = private unnamed_addr constant [13 x i8] c"Result = %d\0A\00", align 1
@str.7 = private unnamed_addr constant [28 x i8] c"Addition Benchmark Complete\00"
@str.8 = private unnamed_addr constant [34 x i8] c"Starting Multiplicaiton Benchmark\00"
@str.9 = private unnamed_addr constant [34 x i8] c"Multiplicaiton Benchmark Complete\00"
@str.10 = private unnamed_addr constant [37 x i8] c"Starting Complex Branching Benchmark\00"
@str.11 = private unnamed_addr constant [37 x i8] c"Complex Branching Benchmark Complete\00"
@totalLoops = global i32 0, align 4
@thread_cond_cpu = local_unnamed_addr global i32 1, align 4
@thread_cond_cgra = local_unnamed_addr global i32 0, align 4
@thread_exit = local_unnamed_addr global i32 0, align 4
@dynamicTCVal = local_unnamed_addr global i32 0, align 4
@initCGRA = common local_unnamed_addr global i32* null, align 4
@epilog = common local_unnamed_addr global i32* null, align 4
@prolog = common local_unnamed_addr global i32* null, align 4
@kernel = common local_unnamed_addr global i32* null, align 4
@prologPtr = common local_unnamed_addr global i32* null, align 4
@epilogPtr = common local_unnamed_addr global i32* null, align 4
@kernelPtr = common local_unnamed_addr global i32* null, align 4
@pth = common global i32 0, align 4
@ArrPtr = common local_unnamed_addr global i32* null, align 4
@configureCGRA.directoryPath = private unnamed_addr constant [20 x i8] c"./CGRAExec/L\00\00\00\00\00\00\00\00", align 1
@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str.1.1 = private unnamed_addr constant [16 x i8] c"/epilog_ins.bin\00", align 1
@.str.2 = private unnamed_addr constant [16 x i8] c"/prolog_ins.bin\00", align 1
@.str.3 = private unnamed_addr constant [16 x i8] c"/kernel_ins.bin\00", align 1
@.str.4 = private unnamed_addr constant [3 x i8] c"rb\00", align 1
@.str.5 = private unnamed_addr constant [32 x i8] c"\0A**********EPISIZE %d*********\0A\00", align 1
@.str.6 = private unnamed_addr constant [32 x i8] c"\0A**********PROSIZE %d*********\0A\00", align 1
@.str.7 = private unnamed_addr constant [33 x i8] c"\0A**********KERNSIZE %d*********\0A\00", align 1
@.str.8 = private unnamed_addr constant [37 x i8] c"\0A******SIZE OF UNISGNED INT %d*****\0A\00", align 1
@.str.9 = private unnamed_addr constant [26 x i8] c"/livevar_st_ins_count.txt\00", align 1
@.str.10 = private unnamed_addr constant [2 x i8] c"r\00", align 1
@.str.11 = private unnamed_addr constant [18 x i8] c"/kernel_count.txt\00", align 1
@.str.12 = private unnamed_addr constant [16 x i8] c"Loop Count: %d\0A\00", align 1
@.str.13 = private unnamed_addr constant [52 x i8] c"From FILE: PROLOGPC= %x, EPILOGPC=%x,  KernelPC=%x\0A\00", align 1
@configureCGRA.initCGRAfile = private unnamed_addr constant [40 x i8] c"./CGRAExec/L1\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00", align 1
@.str.14 = private unnamed_addr constant [14 x i8] c"/initCGRA.txt\00", align 1
@.str.15 = private unnamed_addr constant [3 x i8] c"wb\00", align 1
@.str.16 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@.str.17 = private unnamed_addr constant [5 x i8] c"%ld\0A\00", align 1
@checkTotalLoops.myfile = private unnamed_addr constant [40 x i8] c"./CGRAExec/total_loops.txt\00\00\00\00\00\00\00\00\00\00\00\00\00\00", align 1
@.str.18 = private unnamed_addr constant [3 x i8] c"%u\00", align 1
@.str.20 = private unnamed_addr constant [35 x i8] c"Core will execute loop %u on CGRA\0A\00", align 1
@str.2 = private unnamed_addr constant [14 x i8] c"deleting cgra\00"
@str.24 = private unnamed_addr constant [40 x i8] c"Main thread calling join w/ CGRA thread\00"
@str.25 = private unnamed_addr constant [35 x i8] c"Main thread calling CGRA thread...\00"

; Function Attrs: nounwind
define i32 @main() local_unnamed_addr #0 {
  %1 = tail call i32 @puts(i8* getelementptr inbounds ([28 x i8], [28 x i8]* @str, i32 0, i32 0))
  %2 = tail call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @.str.1, i32 0, i32 0), i32 32640)
  %3 = tail call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @.str.1, i32 0, i32 0), i32 32896)
  %4 = tail call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @.str.1, i32 0, i32 0), i32 33152)
  %5 = tail call i32 @puts(i8* getelementptr inbounds ([28 x i8], [28 x i8]* @str.7, i32 0, i32 0))
  %6 = tail call i32 @puts(i8* getelementptr inbounds ([34 x i8], [34 x i8]* @str.8, i32 0, i32 0))
  %7 = tail call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @.str.1, i32 0, i32 0), i32 0)
  %8 = tail call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @.str.1, i32 0, i32 0), i32 255)
  %9 = tail call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @.str.1, i32 0, i32 0), i32 510)
  %10 = tail call i32 @puts(i8* getelementptr inbounds ([34 x i8], [34 x i8]* @str.9, i32 0, i32 0))
  %11 = tail call i32 @puts(i8* getelementptr inbounds ([37 x i8], [37 x i8]* @str.10, i32 0, i32 0))
  br label %14

; <label>:12:                                     ; preds = %14
  %13 = tail call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @.str.1, i32 0, i32 0), i32 %19)
  br label %26

; <label>:14:                                     ; preds = %14, %0
  %15 = phi i32 [ 0, %0 ], [ %22, %14 ]
  %16 = phi i32 [ 0, %0 ], [ %24, %14 ]
  %17 = phi i32 [ 0, %0 ], [ %19, %14 ]
  %18 = mul nsw i32 %16, %15
  %19 = add nsw i32 %18, %17
  %20 = icmp eq i32 %15, 16
  %21 = add i32 %15, 1
  %22 = select i1 %20, i32 1, i32 %21
  %23 = zext i1 %20 to i32
  %24 = add nsw i32 %16, %23
  %25 = icmp slt i32 %24, 16
  br i1 %25, label %14, label %12

; <label>:26:                                     ; preds = %26, %12
  %27 = phi i32 [ 0, %12 ], [ %34, %26 ]
  %28 = phi i32 [ 0, %12 ], [ %36, %26 ]
  %29 = phi i32 [ 0, %12 ], [ %31, %26 ]
  %30 = mul nsw i32 %28, %27
  %31 = add nsw i32 %30, %29
  %32 = icmp eq i32 %27, 16
  %33 = add i32 %27, 1
  %34 = select i1 %32, i32 1, i32 %33
  %35 = zext i1 %32 to i32
  %36 = add nsw i32 %28, %35
  %37 = icmp slt i32 %36, 16
  br i1 %37, label %26, label %38

; <label>:38:                                     ; preds = %26
  %39 = tail call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @.str.1, i32 0, i32 0), i32 %31)
  br label %40

; <label>:40:                                     ; preds = %40, %38
  %41 = phi i32 [ 0, %38 ], [ %48, %40 ]
  %42 = phi i32 [ 0, %38 ], [ %50, %40 ]
  %43 = phi i32 [ 0, %38 ], [ %45, %40 ]
  %44 = mul nsw i32 %42, %41
  %45 = add nsw i32 %44, %43
  %46 = icmp eq i32 %41, 16
  %47 = add i32 %41, 1
  %48 = select i1 %46, i32 1, i32 %47
  %49 = zext i1 %46 to i32
  %50 = add nsw i32 %42, %49
  %51 = icmp slt i32 %50, 16
  br i1 %51, label %40, label %52

; <label>:52:                                     ; preds = %40
  %53 = tail call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @.str.1, i32 0, i32 0), i32 %45)
  %54 = tail call i32 @puts(i8* getelementptr inbounds ([37 x i8], [37 x i8]* @str.11, i32 0, i32 0))
  ret i32 0
}

; Function Attrs: nounwind
declare i32 @puts(i8* nocapture readonly) local_unnamed_addr #1

; Function Attrs: nounwind
declare i32 @printf(i8* nocapture readonly, ...) local_unnamed_addr #2

; Function Attrs: nounwind
define i32 @initializeParameters(i32) local_unnamed_addr #0 {
  %2 = alloca [25 x i8], align 1
  %3 = alloca [20 x i8], align 1
  %4 = alloca [40 x i8], align 1
  %5 = alloca [40 x i8], align 1
  %6 = alloca [40 x i8], align 1
  %7 = alloca [40 x i8], align 1
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  %10 = alloca i32, align 4
  %11 = alloca i32, align 4
  %12 = alloca [40 x i8], align 1
  %13 = alloca i32, align 4
  %14 = load i32*, i32** @initCGRA, align 4, !tbaa !5
  %15 = add i32 %0, -1
  %16 = mul i32 %15, 7
  %17 = getelementptr inbounds i32, i32* %14, i32 %16
  store i32 2011168768, i32* %17, align 4, !tbaa !9
  %18 = getelementptr inbounds i32, i32* %17, i32 1
  store i32 2011168768, i32* %18, align 4, !tbaa !9
  %19 = getelementptr inbounds i32, i32* %17, i32 2
  %20 = getelementptr inbounds [25 x i8], [25 x i8]* %2, i32 0, i32 0
  %21 = bitcast i32* %19 to i8*
  tail call void @llvm.memset.p0i8.i64(i8* %21, i8 0, i64 20, i32 4, i1 false)
  call void @llvm.lifetime.start(i64 25, i8* nonnull %20) #1
  %22 = getelementptr inbounds [20 x i8], [20 x i8]* %3, i32 0, i32 0
  call void @llvm.lifetime.start(i64 20, i8* nonnull %22) #1
  call void @llvm.memcpy.p0i8.p0i8.i32(i8* nonnull %22, i8* getelementptr inbounds ([20 x i8], [20 x i8]* @configureCGRA.directoryPath, i32 0, i32 0), i32 20, i32 1, i1 false)
  %23 = call i32 (i8*, i8*, ...) @sprintf(i8* nonnull %20, i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i32 0, i32 0), i32 %0) #1
  %24 = call i8* @strcat(i8* nonnull %22, i8* nonnull %20) #1
  %25 = getelementptr inbounds [40 x i8], [40 x i8]* %4, i32 0, i32 0
  call void @llvm.lifetime.start(i64 40, i8* nonnull %25) #1
  call void @llvm.memset.p0i8.i32(i8* nonnull %25, i8 0, i32 40, i32 1, i1 false)
  %26 = getelementptr inbounds [40 x i8], [40 x i8]* %5, i32 0, i32 0
  call void @llvm.lifetime.start(i64 40, i8* nonnull %26) #1
  call void @llvm.memset.p0i8.i32(i8* nonnull %26, i8 0, i32 40, i32 1, i1 false)
  %27 = getelementptr inbounds [40 x i8], [40 x i8]* %6, i32 0, i32 0
  call void @llvm.lifetime.start(i64 40, i8* nonnull %27) #1
  call void @llvm.memset.p0i8.i32(i8* nonnull %27, i8 0, i32 40, i32 1, i1 false)
  %28 = getelementptr inbounds [40 x i8], [40 x i8]* %7, i32 0, i32 0
  call void @llvm.lifetime.start(i64 40, i8* nonnull %28) #1
  call void @llvm.memset.p0i8.i32(i8* nonnull %28, i8 0, i32 40, i32 1, i1 false)
  %29 = call i8* @strcat(i8* nonnull %25, i8* nonnull %22) #1
  %30 = call i32 @strlen(i8* nonnull %25)
  %31 = getelementptr [40 x i8], [40 x i8]* %4, i32 0, i32 %30
  call void @llvm.memcpy.p0i8.p0i8.i32(i8* %31, i8* getelementptr inbounds ([16 x i8], [16 x i8]* @.str.1.1, i32 0, i32 0), i32 16, i32 1, i1 false)
  %32 = call i8* @strcat(i8* nonnull %26, i8* nonnull %22) #1
  %33 = call i32 @strlen(i8* nonnull %26)
  %34 = getelementptr [40 x i8], [40 x i8]* %5, i32 0, i32 %33
  call void @llvm.memcpy.p0i8.p0i8.i32(i8* %34, i8* getelementptr inbounds ([16 x i8], [16 x i8]* @.str.2, i32 0, i32 0), i32 16, i32 1, i1 false)
  %35 = call i8* @strcat(i8* nonnull %27, i8* nonnull %22) #1
  %36 = call i32 @strlen(i8* nonnull %27)
  %37 = getelementptr [40 x i8], [40 x i8]* %6, i32 0, i32 %36
  call void @llvm.memcpy.p0i8.p0i8.i32(i8* %37, i8* getelementptr inbounds ([16 x i8], [16 x i8]* @.str.3, i32 0, i32 0), i32 16, i32 1, i1 false)
  %38 = call %struct._IO_FILE* @fopen(i8* nonnull %25, i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.4, i32 0, i32 0))
  %39 = call %struct._IO_FILE* @fopen(i8* nonnull %26, i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.4, i32 0, i32 0))
  %40 = call %struct._IO_FILE* @fopen(i8* nonnull %27, i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.4, i32 0, i32 0))
  %41 = bitcast i32* %8 to i8*
  call void @llvm.lifetime.start(i64 4, i8* nonnull %41) #1
  %42 = bitcast i32* %9 to i8*
  call void @llvm.lifetime.start(i64 4, i8* nonnull %42) #1
  %43 = bitcast i32* %10 to i8*
  call void @llvm.lifetime.start(i64 4, i8* nonnull %43) #1
  %44 = bitcast i32* %11 to i8*
  call void @llvm.lifetime.start(i64 4, i8* nonnull %44) #1
  %45 = call i32 @fread(i8* nonnull %41, i32 4, i32 1, %struct._IO_FILE* %38)
  %46 = call i32 @fread(i8* nonnull %42, i32 4, i32 1, %struct._IO_FILE* %39)
  %47 = call i32 @fread(i8* nonnull %43, i32 4, i32 1, %struct._IO_FILE* %40)
  %48 = load i32, i32* %8, align 4, !tbaa !9
  %49 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([32 x i8], [32 x i8]* @.str.5, i32 0, i32 0), i32 %48)
  %50 = load i32, i32* %9, align 4, !tbaa !9
  %51 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([32 x i8], [32 x i8]* @.str.6, i32 0, i32 0), i32 %50)
  %52 = load i32, i32* %10, align 4, !tbaa !9
  %53 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([33 x i8], [33 x i8]* @.str.7, i32 0, i32 0), i32 %52)
  %54 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([37 x i8], [37 x i8]* @.str.8, i32 0, i32 0), i32 4)
  %55 = shl i32 %48, 2
  %56 = call noalias i8* @malloc(i32 %55) #1
  store i8* %56, i8** bitcast (i32** @epilog to i8**), align 4, !tbaa !5
  %57 = shl i32 %50, 2
  %58 = call noalias i8* @malloc(i32 %57) #1
  store i8* %58, i8** bitcast (i32** @prolog to i8**), align 4, !tbaa !5
  %59 = shl i32 %52, 2
  %60 = call noalias i8* @malloc(i32 %59) #1
  store i8* %60, i8** bitcast (i32** @kernel to i8**), align 4, !tbaa !5
  %61 = call i32 @fread(i8* %56, i32 4, i32 %48, %struct._IO_FILE* %38)
  %62 = load i8*, i8** bitcast (i32** @prolog to i8**), align 4, !tbaa !5
  %63 = call i32 @fread(i8* %62, i32 4, i32 %50, %struct._IO_FILE* %39)
  %64 = load i8*, i8** bitcast (i32** @kernel to i8**), align 4, !tbaa !5
  %65 = call i32 @fread(i8* %64, i32 4, i32 %52, %struct._IO_FILE* %40)
  %66 = call i8* @strcat(i8* nonnull %28, i8* nonnull %22) #1
  %67 = call i32 @strlen(i8* nonnull %28)
  %68 = getelementptr [40 x i8], [40 x i8]* %7, i32 0, i32 %67
  call void @llvm.memcpy.p0i8.p0i8.i32(i8* %68, i8* getelementptr inbounds ([26 x i8], [26 x i8]* @.str.9, i32 0, i32 0), i32 26, i32 1, i1 false)
  %69 = call %struct._IO_FILE* @fopen(i8* nonnull %28, i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.10, i32 0, i32 0))
  %70 = call i32 (%struct._IO_FILE*, i8*, ...) @__isoc99_fscanf(%struct._IO_FILE* %69, i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i32 0, i32 0), i32* nonnull %11) #1
  %71 = sdiv i32 %52, 36
  %72 = sdiv i32 %48, 36
  %73 = sdiv i32 %50, 36
  %74 = load i32*, i32** @initCGRA, align 4, !tbaa !5
  %75 = getelementptr inbounds i32, i32* %74, i32 %16
  %76 = getelementptr inbounds i32, i32* %75, i32 2
  store i32 %71, i32* %76, align 4, !tbaa !9
  %77 = getelementptr inbounds i32, i32* %75, i32 3
  store i32 %72, i32* %77, align 4, !tbaa !9
  %78 = getelementptr inbounds i32, i32* %75, i32 4
  store i32 %73, i32* %78, align 4, !tbaa !9
  %79 = load i32, i32* %11, align 4, !tbaa !9
  %80 = sdiv i32 %79, 36
  %81 = getelementptr inbounds i32, i32* %75, i32 6
  store i32 %80, i32* %81, align 4, !tbaa !9
  %82 = call i32 @fclose(%struct._IO_FILE* %38)
  %83 = call i32 @fclose(%struct._IO_FILE* %39)
  %84 = call i32 @fclose(%struct._IO_FILE* %40)
  %85 = call i32 @fclose(%struct._IO_FILE* %69)
  %86 = getelementptr inbounds [40 x i8], [40 x i8]* %12, i32 0, i32 0
  call void @llvm.lifetime.start(i64 40, i8* nonnull %86) #1
  call void @llvm.memset.p0i8.i32(i8* nonnull %86, i8 0, i32 40, i32 1, i1 false)
  %87 = call i8* @strcat(i8* nonnull %86, i8* nonnull %22) #1
  %88 = call i32 @strlen(i8* nonnull %86)
  %89 = getelementptr [40 x i8], [40 x i8]* %12, i32 0, i32 %88
  call void @llvm.memcpy.p0i8.p0i8.i32(i8* %89, i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.11, i32 0, i32 0), i32 18, i32 1, i1 false)
  %90 = bitcast i32* %13 to i8*
  call void @llvm.lifetime.start(i64 4, i8* nonnull %90) #1
  store i32 0, i32* %13, align 4, !tbaa !9
  %91 = call %struct._IO_FILE* @fopen(i8* nonnull %86, i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.10, i32 0, i32 0))
  %92 = call i32 (%struct._IO_FILE*, i8*, ...) @__isoc99_fscanf(%struct._IO_FILE* %91, i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i32 0, i32 0), i32* nonnull %13) #1
  %93 = call i32 @fclose(%struct._IO_FILE* %91)
  %94 = load i32, i32* %13, align 4, !tbaa !9
  %95 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([16 x i8], [16 x i8]* @.str.12, i32 0, i32 0), i32 %94)
  %96 = load i32, i32* %13, align 4, !tbaa !9
  %97 = load i32*, i32** @initCGRA, align 4, !tbaa !5
  %98 = getelementptr inbounds i32, i32* %97, i32 %16
  %99 = getelementptr inbounds i32, i32* %98, i32 5
  store i32 %96, i32* %99, align 4, !tbaa !9
  %100 = load i32, i32* bitcast (i32** @prolog to i32*), align 4, !tbaa !5
  %101 = load i32, i32* bitcast (i32** @epilog to i32*), align 4, !tbaa !5
  %102 = load i32, i32* bitcast (i32** @kernel to i32*), align 4, !tbaa !5
  %103 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([52 x i8], [52 x i8]* @.str.13, i32 0, i32 0), i32 %100, i32 %101, i32 %102)
  %104 = load i32, i32* bitcast (i32** @prolog to i32*), align 4, !tbaa !5
  %105 = load i32*, i32** @prologPtr, align 4, !tbaa !5
  %106 = getelementptr inbounds i32, i32* %105, i32 %15
  store i32 %104, i32* %106, align 4, !tbaa !11
  %107 = load i32, i32* bitcast (i32** @epilog to i32*), align 4, !tbaa !5
  %108 = load i32*, i32** @epilogPtr, align 4, !tbaa !5
  %109 = getelementptr inbounds i32, i32* %108, i32 %15
  store i32 %107, i32* %109, align 4, !tbaa !11
  %110 = load i32, i32* bitcast (i32** @kernel to i32*), align 4, !tbaa !5
  %111 = load i32*, i32** @kernelPtr, align 4, !tbaa !5
  %112 = getelementptr inbounds i32, i32* %111, i32 %15
  store i32 %110, i32* %112, align 4, !tbaa !11
  call void @llvm.lifetime.end(i64 4, i8* nonnull %90) #1
  call void @llvm.lifetime.end(i64 40, i8* nonnull %86) #1
  call void @llvm.lifetime.end(i64 4, i8* nonnull %44) #1
  call void @llvm.lifetime.end(i64 4, i8* nonnull %43) #1
  call void @llvm.lifetime.end(i64 4, i8* nonnull %42) #1
  call void @llvm.lifetime.end(i64 4, i8* nonnull %41) #1
  call void @llvm.lifetime.end(i64 40, i8* nonnull %28) #1
  call void @llvm.lifetime.end(i64 40, i8* nonnull %27) #1
  call void @llvm.lifetime.end(i64 40, i8* nonnull %26) #1
  call void @llvm.lifetime.end(i64 40, i8* nonnull %25) #1
  call void @llvm.lifetime.end(i64 20, i8* nonnull %22) #1
  call void @llvm.lifetime.end(i64 25, i8* nonnull %20) #1
  ret i32 0
}

; Function Attrs: argmemonly nounwind
declare void @llvm.memset.p0i8.i64(i8* nocapture writeonly, i8, i64, i32, i1) #3

; Function Attrs: argmemonly nounwind
declare void @llvm.lifetime.start(i64, i8* nocapture) #3

; Function Attrs: argmemonly nounwind
declare void @llvm.memcpy.p0i8.p0i8.i32(i8* nocapture writeonly, i8* nocapture readonly, i32, i32, i1) #3

; Function Attrs: nounwind
declare i32 @sprintf(i8* nocapture, i8* nocapture readonly, ...) local_unnamed_addr #2

; Function Attrs: nounwind
declare i8* @strcat(i8*, i8* nocapture readonly) local_unnamed_addr #2

; Function Attrs: argmemonly nounwind
declare void @llvm.memset.p0i8.i32(i8* nocapture writeonly, i8, i32, i32, i1) #3

; Function Attrs: nounwind readonly
declare i32 @strlen(i8* nocapture) local_unnamed_addr #4

; Function Attrs: nounwind
declare noalias %struct._IO_FILE* @fopen(i8* nocapture readonly, i8* nocapture readonly) local_unnamed_addr #2

; Function Attrs: nounwind
declare i32 @fread(i8* nocapture, i32, i32, %struct._IO_FILE* nocapture) local_unnamed_addr #2

; Function Attrs: nounwind
declare noalias i8* @malloc(i32) local_unnamed_addr #2

declare i32 @__isoc99_fscanf(%struct._IO_FILE*, i8*, ...) local_unnamed_addr #5

; Function Attrs: nounwind
declare i32 @fclose(%struct._IO_FILE* nocapture) local_unnamed_addr #2

; Function Attrs: argmemonly nounwind
declare void @llvm.lifetime.end(i64, i8* nocapture) #3

; Function Attrs: nounwind
define i32 @configureCGRA(i32) local_unnamed_addr #0 {
  %2 = alloca [25 x i8], align 1
  %3 = alloca [20 x i8], align 1
  %4 = alloca [40 x i8], align 1
  %5 = load i32*, i32** @initCGRA, align 4, !tbaa !5
  %6 = add i32 %0, -1
  %7 = mul i32 %6, 7
  %8 = getelementptr inbounds i32, i32* %5, i32 %7
  %9 = getelementptr inbounds i32, i32* %8, i32 5
  %10 = load i32, i32* %9, align 4, !tbaa !9
  %11 = getelementptr inbounds [25 x i8], [25 x i8]* %2, i32 0, i32 0
  call void @llvm.lifetime.start(i64 25, i8* nonnull %11) #1
  %12 = getelementptr inbounds [20 x i8], [20 x i8]* %3, i32 0, i32 0
  call void @llvm.lifetime.start(i64 20, i8* nonnull %12) #1
  call void @llvm.memcpy.p0i8.p0i8.i32(i8* nonnull %12, i8* getelementptr inbounds ([20 x i8], [20 x i8]* @configureCGRA.directoryPath, i32 0, i32 0), i32 20, i32 1, i1 false)
  %13 = call i32 (i8*, i8*, ...) @sprintf(i8* nonnull %11, i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i32 0, i32 0), i32 %0) #1
  %14 = call i8* @strcat(i8* nonnull %12, i8* nonnull %11) #1
  %15 = icmp slt i32 %10, 1
  br i1 %15, label %16, label %22

; <label>:16:                                     ; preds = %1
  %17 = load i32, i32* @dynamicTCVal, align 4, !tbaa !9
  %18 = add nsw i32 %17, %10
  %19 = load i32*, i32** @initCGRA, align 4, !tbaa !5
  %20 = getelementptr inbounds i32, i32* %19, i32 %7
  %21 = getelementptr inbounds i32, i32* %20, i32 5
  store i32 %18, i32* %21, align 4, !tbaa !9
  br label %22

; <label>:22:                                     ; preds = %16, %1
  %23 = getelementptr inbounds [40 x i8], [40 x i8]* %4, i32 0, i32 0
  call void @llvm.lifetime.start(i64 40, i8* nonnull %23) #1
  call void @llvm.memcpy.p0i8.p0i8.i32(i8* nonnull %23, i8* getelementptr inbounds ([40 x i8], [40 x i8]* @configureCGRA.initCGRAfile, i32 0, i32 0), i32 40, i32 1, i1 false)
  %24 = call i32 @strlen(i8* nonnull %23)
  %25 = getelementptr [40 x i8], [40 x i8]* %4, i32 0, i32 %24
  call void @llvm.memcpy.p0i8.p0i8.i32(i8* %25, i8* getelementptr inbounds ([14 x i8], [14 x i8]* @.str.14, i32 0, i32 0), i32 14, i32 1, i1 false)
  %26 = call %struct._IO_FILE* @fopen(i8* nonnull %23, i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.15, i32 0, i32 0))
  %27 = load i32*, i32** @initCGRA, align 4, !tbaa !5
  %28 = getelementptr inbounds i32, i32* %27, i32 %7
  %29 = load i32, i32* %28, align 4, !tbaa !9
  %30 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %26, i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.16, i32 0, i32 0), i32 %29)
  %31 = load i32*, i32** @initCGRA, align 4, !tbaa !5
  %32 = getelementptr inbounds i32, i32* %31, i32 %7
  %33 = getelementptr inbounds i32, i32* %32, i32 1
  %34 = load i32, i32* %33, align 4, !tbaa !9
  %35 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %26, i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.16, i32 0, i32 0), i32 %34)
  %36 = load i32*, i32** @initCGRA, align 4, !tbaa !5
  %37 = getelementptr inbounds i32, i32* %36, i32 %7
  %38 = getelementptr inbounds i32, i32* %37, i32 2
  %39 = load i32, i32* %38, align 4, !tbaa !9
  %40 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %26, i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.16, i32 0, i32 0), i32 %39)
  %41 = load i32*, i32** @initCGRA, align 4, !tbaa !5
  %42 = getelementptr inbounds i32, i32* %41, i32 %7
  %43 = getelementptr inbounds i32, i32* %42, i32 3
  %44 = load i32, i32* %43, align 4, !tbaa !9
  %45 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %26, i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.16, i32 0, i32 0), i32 %44)
  %46 = load i32*, i32** @initCGRA, align 4, !tbaa !5
  %47 = getelementptr inbounds i32, i32* %46, i32 %7
  %48 = getelementptr inbounds i32, i32* %47, i32 4
  %49 = load i32, i32* %48, align 4, !tbaa !9
  %50 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %26, i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.16, i32 0, i32 0), i32 %49)
  %51 = load i32*, i32** @initCGRA, align 4, !tbaa !5
  %52 = getelementptr inbounds i32, i32* %51, i32 %7
  %53 = getelementptr inbounds i32, i32* %52, i32 5
  %54 = load i32, i32* %53, align 4, !tbaa !9
  %55 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %26, i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.16, i32 0, i32 0), i32 %54)
  %56 = load i32*, i32** @initCGRA, align 4, !tbaa !5
  %57 = getelementptr inbounds i32, i32* %56, i32 %7
  %58 = getelementptr inbounds i32, i32* %57, i32 6
  %59 = load i32, i32* %58, align 4, !tbaa !9
  %60 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %26, i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.16, i32 0, i32 0), i32 %59)
  %61 = load i32*, i32** @epilogPtr, align 4, !tbaa !5
  %62 = getelementptr inbounds i32, i32* %61, i32 %6
  %63 = load i32, i32* %62, align 4, !tbaa !11
  %64 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %26, i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.17, i32 0, i32 0), i32 %63)
  %65 = load i32*, i32** @prologPtr, align 4, !tbaa !5
  %66 = getelementptr inbounds i32, i32* %65, i32 %6
  %67 = load i32, i32* %66, align 4, !tbaa !11
  %68 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %26, i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.17, i32 0, i32 0), i32 %67)
  %69 = load i32*, i32** @kernelPtr, align 4, !tbaa !5
  %70 = getelementptr inbounds i32, i32* %69, i32 %6
  %71 = load i32, i32* %70, align 4, !tbaa !11
  %72 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %26, i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.17, i32 0, i32 0), i32 %71)
  %73 = call i32 @fclose(%struct._IO_FILE* %26)
  call void @llvm.lifetime.end(i64 40, i8* nonnull %23) #1
  call void @llvm.lifetime.end(i64 20, i8* nonnull %12) #1
  call void @llvm.lifetime.end(i64 25, i8* nonnull %11) #1
  ret i32 0
}

; Function Attrs: nounwind
declare i32 @fprintf(%struct._IO_FILE* nocapture, i8* nocapture readonly, ...) local_unnamed_addr #2

; Function Attrs: nounwind
define void @checkTotalLoops() local_unnamed_addr #0 {
  %1 = alloca [40 x i8], align 1
  %2 = getelementptr inbounds [40 x i8], [40 x i8]* %1, i32 0, i32 0
  call void @llvm.lifetime.start(i64 40, i8* nonnull %2) #1
  call void @llvm.memcpy.p0i8.p0i8.i32(i8* nonnull %2, i8* getelementptr inbounds ([40 x i8], [40 x i8]* @checkTotalLoops.myfile, i32 0, i32 0), i32 40, i32 1, i1 false)
  %3 = call %struct._IO_FILE* @fopen(i8* nonnull %2, i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.10, i32 0, i32 0))
  %4 = tail call i32 (%struct._IO_FILE*, i8*, ...) @__isoc99_fscanf(%struct._IO_FILE* %3, i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.18, i32 0, i32 0), i32* nonnull @totalLoops) #1
  %5 = tail call i32 @fclose(%struct._IO_FILE* %3)
  call void @llvm.lifetime.end(i64 40, i8* nonnull %2) #1
  ret void
}

; Function Attrs: nounwind
define noalias i8* @runOnCGRA(i8* nocapture readnone) #0 {
  br label %2

; <label>:2:                                      ; preds = %11, %1
  %3 = load i32, i32* @thread_cond_cgra, align 4, !tbaa !9
  %4 = icmp eq i32 %3, 1
  br i1 %4, label %.loopexit, label %.preheader.preheader

.preheader.preheader:                             ; preds = %2
  br label %.preheader

.preheader:                                       ; preds = %.preheader.preheader, %.preheader
  %5 = tail call i32 @usleep(i32 1) #1
  %6 = load i32, i32* @thread_cond_cgra, align 4, !tbaa !9
  %7 = icmp eq i32 %6, 1
  br i1 %7, label %.loopexit.loopexit, label %.preheader, !llvm.loop !13

.loopexit.loopexit:                               ; preds = %.preheader
  br label %.loopexit

.loopexit:                                        ; preds = %.loopexit.loopexit, %2
  %8 = load i32, i32* @thread_exit, align 4, !tbaa !9
  %9 = icmp eq i32 %8, 1
  br i1 %9, label %10, label %11

; <label>:10:                                     ; preds = %.loopexit
  tail call void asm sideeffect "mov r11,$0", "r"(i32 17) #1, !srcloc !65
  ret i8* null

; <label>:11:                                     ; preds = %.loopexit
  store i32 0, i32* @thread_cond_cgra, align 4, !tbaa !9
  tail call void asm sideeffect "mov r11,$0", "r"(i32 15) #1, !srcloc !66
  %12 = tail call i32 @usleep(i32 1) #1
  store i32 1, i32* @thread_cond_cpu, align 4, !tbaa !9
  br label %2, !llvm.loop !67
}

declare i32 @usleep(i32) local_unnamed_addr #5

; Function Attrs: nounwind
define void @accelerateOnCGRA(i32) local_unnamed_addr #0 {
  %2 = tail call i32 @configureCGRA(i32 %0)
  %3 = tail call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([35 x i8], [35 x i8]* @.str.20, i32 0, i32 0), i32 %0)
  store i32 0, i32* @thread_cond_cpu, align 4, !tbaa !9
  store i32 1, i32* @thread_cond_cgra, align 4, !tbaa !9
  br label %4

; <label>:4:                                      ; preds = %4, %1
  %5 = tail call i32 @usleep(i32 1) #1
  %6 = load i32, i32* @thread_cond_cpu, align 4, !tbaa !9
  %7 = icmp eq i32 %6, 1
  br i1 %7, label %8, label %4, !llvm.loop !69

; <label>:8:                                      ; preds = %4
  ret void
}

; Function Attrs: nounwind
define void @deleteCGRA() local_unnamed_addr #0 {
  %1 = tail call i32 @puts(i8* getelementptr inbounds ([14 x i8], [14 x i8]* @str.2, i32 0, i32 0))
  store i32 1, i32* @thread_exit, align 4, !tbaa !9
  store i32 1, i32* @thread_cond_cgra, align 4, !tbaa !9
  %2 = tail call i32 @puts(i8* getelementptr inbounds ([40 x i8], [40 x i8]* @str.24, i32 0, i32 0))
  %3 = load i32, i32* @pth, align 4, !tbaa !11
  %4 = tail call i32 @pthread_join(i32 %3, i8** null) #1
  ret void
}

declare i32 @pthread_join(i32, i8**) local_unnamed_addr #5

; Function Attrs: nounwind
define void @createCGRA() local_unnamed_addr #0 {
  %1 = alloca [40 x i8], align 1
  %2 = getelementptr inbounds [40 x i8], [40 x i8]* %1, i32 0, i32 0
  call void @llvm.lifetime.start(i64 40, i8* nonnull %2) #1
  call void @llvm.memcpy.p0i8.p0i8.i32(i8* nonnull %2, i8* getelementptr inbounds ([40 x i8], [40 x i8]* @checkTotalLoops.myfile, i32 0, i32 0), i32 40, i32 1, i1 false) #1
  %3 = call %struct._IO_FILE* @fopen(i8* nonnull %2, i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.10, i32 0, i32 0)) #1
  %4 = tail call i32 (%struct._IO_FILE*, i8*, ...) @__isoc99_fscanf(%struct._IO_FILE* %3, i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.18, i32 0, i32 0), i32* nonnull @totalLoops) #1
  %5 = tail call i32 @fclose(%struct._IO_FILE* %3) #1
  call void @llvm.lifetime.end(i64 40, i8* nonnull %2) #1
  %6 = load i32, i32* @totalLoops, align 4, !tbaa !9
  %7 = mul i32 %6, 28
  %8 = tail call noalias i8* @malloc(i32 %7) #1
  store i8* %8, i8** bitcast (i32** @initCGRA to i8**), align 4, !tbaa !5
  %9 = shl i32 %6, 2
  %10 = tail call noalias i8* @malloc(i32 %9) #1
  store i8* %10, i8** bitcast (i32** @prologPtr to i8**), align 4, !tbaa !5
  %11 = tail call noalias i8* @malloc(i32 %9) #1
  store i8* %11, i8** bitcast (i32** @kernelPtr to i8**), align 4, !tbaa !5
  %12 = tail call noalias i8* @malloc(i32 %9) #1
  store i8* %12, i8** bitcast (i32** @epilogPtr to i8**), align 4, !tbaa !5
  %13 = icmp eq i32 %6, 0
  br i1 %13, label %.loopexit, label %.preheader.preheader

.preheader.preheader:                             ; preds = %0
  br label %.preheader

.preheader:                                       ; preds = %.preheader.preheader, %.preheader
  %14 = phi i32 [ %16, %.preheader ], [ 1, %.preheader.preheader ]
  %15 = tail call i32 @initializeParameters(i32 %14)
  %16 = add i32 %14, 1
  %17 = load i32, i32* @totalLoops, align 4, !tbaa !9
  %18 = icmp ugt i32 %16, %17
  br i1 %18, label %.loopexit.loopexit, label %.preheader, !llvm.loop !78

.loopexit.loopexit:                               ; preds = %.preheader
  br label %.loopexit

.loopexit:                                        ; preds = %.loopexit.loopexit, %0
  %19 = tail call i32 @puts(i8* getelementptr inbounds ([35 x i8], [35 x i8]* @str.25, i32 0, i32 0))
  %20 = tail call i32 @pthread_create(i32* nonnull @pth, %union.pthread_attr_t* null, i8* (i8*)* nonnull @runOnCGRA, i8* null) #1
  ret void
}

; Function Attrs: nounwind
declare i32 @pthread_create(i32*, %union.pthread_attr_t*, i8* (i8*)*, i8*) local_unnamed_addr #2

attributes #0 = { nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="cortex-a8" "target-features"="+dsp,+neon,+vfp3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind }
attributes #2 = { nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="cortex-a8" "target-features"="+dsp,+neon,+vfp3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { argmemonly nounwind }
attributes #4 = { nounwind readonly }
attributes #5 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="cortex-a8" "target-features"="+dsp,+neon,+vfp3" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0, !0}
!llvm.module.flags = !{!1, !2, !3, !4}

!0 = !{!"clang version 5.0.0 (trunk 296996) (llvm/trunk 296995)"}
!1 = !{i32 2, !"Dwarf Version", i32 4}
!2 = !{i32 2, !"Debug Info Version", i32 3}
!3 = !{i32 1, !"wchar_size", i32 4}
!4 = !{i32 1, !"min_enum_size", i32 4}
!5 = !{!6, !6, i64 0}
!6 = !{!"any pointer", !7, i64 0}
!7 = !{!"omnipotent char", !8, i64 0}
!8 = !{!"Simple C/C++ TBAA"}
!9 = !{!10, !10, i64 0}
!10 = !{!"int", !7, i64 0}
!11 = !{!12, !12, i64 0}
!12 = !{!"long", !7, i64 0}
!13 = distinct !{!13, !14}
!14 = !DILocation(line: 149, column: 46, scope: !15)
!15 = distinct !DILexicalBlock(scope: !17, file: !16, line: 148, column: 14)
!16 = !DIFile(filename: "/home/lincoln/ccf_6x6/ccf/scripts/CGRALib/cgra.c", directory: "/home/lincoln/ccf_6x6/ccf/work/benchmarks/MiBench/basicmath-CCF/benchmark")
!17 = distinct !DISubprogram(name: "runOnCGRA", scope: !16, file: !16, line: 145, type: !18, isLocal: false, isDefinition: true, scopeLine: 146, flags: DIFlagPrototyped, isOptimized: true, unit: !21, variables: !63)
!18 = !DISubroutineType(types: !19)
!19 = !{!20, !20}
!20 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: null, size: 32)
!21 = distinct !DICompileUnit(language: DW_LANG_C99, file: !16, producer: "clang version 5.0.0 (trunk 296996) (llvm/trunk 296995)", isOptimized: true, runtimeVersion: 0, emissionKind: FullDebug, enums: !22, retainedTypes: !23, globals: !29)
!22 = !{}
!23 = !{!24, !25, !26, !20, !27}
!24 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !25, size: 32)
!25 = !DIBasicType(name: "unsigned int", size: 32, encoding: DW_ATE_unsigned)
!26 = !DIBasicType(name: "long int", size: 32, encoding: DW_ATE_signed)
!27 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !28, size: 32)
!28 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!29 = !{!30, !33, !35, !37, !39, !41, !43, !45, !47, !49, !52, !54, !56, !58}
!30 = !DIGlobalVariableExpression(var: !31)
!31 = distinct !DIGlobalVariable(name: "totalLoops", scope: !21, file: !32, line: 29, type: !25, isLocal: false, isDefinition: true)
!32 = !DIFile(filename: "/home/lincoln/ccf_6x6/ccf/scripts/CGRALib/cgra.h", directory: "/home/lincoln/ccf_6x6/ccf/work/benchmarks/MiBench/basicmath-CCF/benchmark")
!33 = !DIGlobalVariableExpression(var: !34)
!34 = distinct !DIGlobalVariable(name: "thread_cond_cpu", scope: !21, file: !32, line: 32, type: !25, isLocal: false, isDefinition: true)
!35 = !DIGlobalVariableExpression(var: !36)
!36 = distinct !DIGlobalVariable(name: "thread_cond_cgra", scope: !21, file: !32, line: 33, type: !25, isLocal: false, isDefinition: true)
!37 = !DIGlobalVariableExpression(var: !38)
!38 = distinct !DIGlobalVariable(name: "thread_exit", scope: !21, file: !32, line: 34, type: !25, isLocal: false, isDefinition: true)
!39 = !DIGlobalVariableExpression(var: !40)
!40 = distinct !DIGlobalVariable(name: "dynamicTCVal", scope: !21, file: !32, line: 36, type: !28, isLocal: false, isDefinition: true)
!41 = !DIGlobalVariableExpression(var: !42)
!42 = distinct !DIGlobalVariable(name: "prolog", scope: !21, file: !32, line: 23, type: !24, isLocal: false, isDefinition: true)
!43 = !DIGlobalVariableExpression(var: !44)
!44 = distinct !DIGlobalVariable(name: "epilog", scope: !21, file: !32, line: 23, type: !24, isLocal: false, isDefinition: true)
!45 = !DIGlobalVariableExpression(var: !46)
!46 = distinct !DIGlobalVariable(name: "kernel", scope: !21, file: !32, line: 23, type: !24, isLocal: false, isDefinition: true)
!47 = !DIGlobalVariableExpression(var: !48)
!48 = distinct !DIGlobalVariable(name: "ArrPtr", scope: !21, file: !32, line: 24, type: !24, isLocal: false, isDefinition: true)
!49 = !DIGlobalVariableExpression(var: !50)
!50 = distinct !DIGlobalVariable(name: "prologPtr", scope: !21, file: !32, line: 26, type: !51, isLocal: false, isDefinition: true)
!51 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !26, size: 32)
!52 = !DIGlobalVariableExpression(var: !53)
!53 = distinct !DIGlobalVariable(name: "kernelPtr", scope: !21, file: !32, line: 26, type: !51, isLocal: false, isDefinition: true)
!54 = !DIGlobalVariableExpression(var: !55)
!55 = distinct !DIGlobalVariable(name: "epilogPtr", scope: !21, file: !32, line: 26, type: !51, isLocal: false, isDefinition: true)
!56 = !DIGlobalVariableExpression(var: !57)
!57 = distinct !DIGlobalVariable(name: "initCGRA", scope: !21, file: !32, line: 28, type: !27, isLocal: false, isDefinition: true)
!58 = !DIGlobalVariableExpression(var: !59)
!59 = distinct !DIGlobalVariable(name: "pth", scope: !21, file: !32, line: 31, type: !60, isLocal: false, isDefinition: true)
!60 = !DIDerivedType(tag: DW_TAG_typedef, name: "pthread_t", file: !61, line: 37, baseType: !62)
!61 = !DIFile(filename: "/usr/arm-linux-gnueabi/include/bits/pthreadtypes.h", directory: "/home/lincoln/ccf_6x6/ccf/work/benchmarks/MiBench/basicmath-CCF/benchmark")
!62 = !DIBasicType(name: "long unsigned int", size: 32, encoding: DW_ATE_unsigned)
!63 = !{!64}
!64 = !DILocalVariable(name: "arg", arg: 1, scope: !17, file: !16, line: 145, type: !20)
!65 = !{i32 4153}
!66 = !{i32 4261}
!67 = distinct !{!67, !68}
!68 = !DILocation(line: 160, column: 5, scope: !17)
!69 = distinct !{!69, !70}
!70 = !DILocation(line: 178, column: 41, scope: !71)
!71 = distinct !DISubprogram(name: "accelerateOnCGRA", scope: !16, file: !16, line: 164, type: !72, isLocal: false, isDefinition: true, scopeLine: 165, flags: DIFlagPrototyped, isOptimized: true, unit: !21, variables: !74)
!72 = !DISubroutineType(types: !73)
!73 = !{null, !25}
!74 = !{!75, !76, !77}
!75 = !DILocalVariable(name: "loopNo", arg: 1, scope: !71, file: !16, line: 164, type: !25)
!76 = !DILocalVariable(name: "result", scope: !71, file: !16, line: 166, type: !28)
!77 = !DILocalVariable(name: "configure", scope: !71, file: !16, line: 168, type: !28)
!78 = distinct !{!78, !79}
!79 = !DILocation(line: 206, column: 29, scope: !80)
!80 = distinct !DILexicalBlock(scope: !81, file: !16, line: 205, column: 3)
!81 = distinct !DISubprogram(name: "createCGRA", scope: !16, file: !16, line: 193, type: !82, isLocal: false, isDefinition: true, scopeLine: 194, isOptimized: true, unit: !21, variables: !84)
!82 = !DISubroutineType(types: !83)
!83 = !{null}
!84 = !{!85, !86}
!85 = !DILocalVariable(name: "result", scope: !81, file: !16, line: 195, type: !28)
!86 = !DILocalVariable(name: "i", scope: !81, file: !16, line: 196, type: !25)
