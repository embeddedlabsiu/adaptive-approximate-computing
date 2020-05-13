; ModuleID = 'bench.c'
source_filename = "bench.c"
target datalayout = "e-m:e-p:32:32-i64:64-v128:64:128-a:0:32-n32-S64"
target triple = "armv7--linux-eabi"

@.str.1 = private unnamed_addr constant [13 x i8] c"Result = %d\0A\00", align 1
@str = private unnamed_addr constant [28 x i8] c"Starting Addition Benchmark\00"
@str.7 = private unnamed_addr constant [28 x i8] c"Addition Benchmark Complete\00"
@str.8 = private unnamed_addr constant [34 x i8] c"Starting Multiplicaiton Benchmark\00"
@str.9 = private unnamed_addr constant [34 x i8] c"Multiplicaiton Benchmark Complete\00"
@str.10 = private unnamed_addr constant [37 x i8] c"Starting Complex Branching Benchmark\00"
@str.11 = private unnamed_addr constant [37 x i8] c"Complex Branching Benchmark Complete\00"

; Function Attrs: nounwind
define i32 @main() local_unnamed_addr #0 !dbg !8 {
  %1 = tail call i32 @puts(i8* getelementptr inbounds ([28 x i8], [28 x i8]* @str, i32 0, i32 0)), !dbg !33
  tail call void @llvm.dbg.value(metadata i32 0, i64 0, metadata !13, metadata !34), !dbg !35
  tail call void @llvm.dbg.value(metadata i32 0, i64 0, metadata !13, metadata !34), !dbg !35
  tail call void @llvm.dbg.value(metadata i32 0, i64 0, metadata !14, metadata !34), !dbg !36
  %2 = tail call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @.str.1, i32 0, i32 0), i32 32640), !dbg !37
  tail call void @llvm.dbg.value(metadata i32 1, i64 0, metadata !13, metadata !34), !dbg !35
  tail call void @llvm.dbg.value(metadata i32 1, i64 0, metadata !13, metadata !34), !dbg !35
  tail call void @llvm.dbg.value(metadata i32 0, i64 0, metadata !14, metadata !34), !dbg !36
  %3 = tail call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @.str.1, i32 0, i32 0), i32 32896), !dbg !37
  tail call void @llvm.dbg.value(metadata i32 1, i64 0, metadata !13, metadata !34), !dbg !35
  tail call void @llvm.dbg.value(metadata i32 1, i64 0, metadata !13, metadata !34), !dbg !35
  tail call void @llvm.dbg.value(metadata i32 0, i64 0, metadata !14, metadata !34), !dbg !36
  %4 = tail call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @.str.1, i32 0, i32 0), i32 33152), !dbg !37
  tail call void @llvm.dbg.value(metadata i32 1, i64 0, metadata !13, metadata !34), !dbg !35
  tail call void @llvm.dbg.value(metadata i32 1, i64 0, metadata !13, metadata !34), !dbg !35
  %5 = tail call i32 @puts(i8* getelementptr inbounds ([28 x i8], [28 x i8]* @str.7, i32 0, i32 0)), !dbg !38
  %6 = tail call i32 @puts(i8* getelementptr inbounds ([34 x i8], [34 x i8]* @str.8, i32 0, i32 0)), !dbg !39
  tail call void @llvm.dbg.value(metadata i32 0, i64 0, metadata !13, metadata !34), !dbg !35
  tail call void @llvm.dbg.value(metadata i32 0, i64 0, metadata !13, metadata !34), !dbg !35
  tail call void @llvm.dbg.value(metadata i32 0, i64 0, metadata !20, metadata !34), !dbg !40
  %7 = tail call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @.str.1, i32 0, i32 0), i32 0), !dbg !41
  tail call void @llvm.dbg.value(metadata i32 1, i64 0, metadata !13, metadata !34), !dbg !35
  tail call void @llvm.dbg.value(metadata i32 1, i64 0, metadata !13, metadata !34), !dbg !35
  tail call void @llvm.dbg.value(metadata i32 0, i64 0, metadata !20, metadata !34), !dbg !40
  %8 = tail call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @.str.1, i32 0, i32 0), i32 255), !dbg !41
  tail call void @llvm.dbg.value(metadata i32 1, i64 0, metadata !13, metadata !34), !dbg !35
  tail call void @llvm.dbg.value(metadata i32 1, i64 0, metadata !13, metadata !34), !dbg !35
  tail call void @llvm.dbg.value(metadata i32 0, i64 0, metadata !20, metadata !34), !dbg !40
  %9 = tail call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @.str.1, i32 0, i32 0), i32 510), !dbg !41
  tail call void @llvm.dbg.value(metadata i32 1, i64 0, metadata !13, metadata !34), !dbg !35
  tail call void @llvm.dbg.value(metadata i32 1, i64 0, metadata !13, metadata !34), !dbg !35
  %10 = tail call i32 @puts(i8* getelementptr inbounds ([34 x i8], [34 x i8]* @str.9, i32 0, i32 0)), !dbg !42
  %11 = tail call i32 @puts(i8* getelementptr inbounds ([37 x i8], [37 x i8]* @str.10, i32 0, i32 0)), !dbg !43
  tail call void @llvm.dbg.value(metadata i32 0, i64 0, metadata !13, metadata !34), !dbg !35
  tail call void @llvm.dbg.value(metadata i32 0, i64 0, metadata !13, metadata !34), !dbg !35
  tail call void @llvm.dbg.value(metadata i32 0, i64 0, metadata !31, metadata !34), !dbg !44
  tail call void @llvm.dbg.value(metadata i32 0, i64 0, metadata !30, metadata !34), !dbg !45
  tail call void @llvm.dbg.value(metadata i32 0, i64 0, metadata !26, metadata !34), !dbg !46
  br label %14, !dbg !47

; <label>:12:                                     ; preds = %14
  %13 = tail call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @.str.1, i32 0, i32 0), i32 %19), !dbg !48
  tail call void @llvm.dbg.value(metadata i32 1, i64 0, metadata !13, metadata !34), !dbg !35
  tail call void @llvm.dbg.value(metadata i32 1, i64 0, metadata !13, metadata !34), !dbg !35
  tail call void @llvm.dbg.value(metadata i32 0, i64 0, metadata !31, metadata !34), !dbg !44
  tail call void @llvm.dbg.value(metadata i32 0, i64 0, metadata !30, metadata !34), !dbg !45
  tail call void @llvm.dbg.value(metadata i32 0, i64 0, metadata !26, metadata !34), !dbg !46
  br label %26, !dbg !47

; <label>:14:                                     ; preds = %0, %14
  %15 = phi i32 [ 0, %0 ], [ %22, %14 ]
  %16 = phi i32 [ 0, %0 ], [ %24, %14 ]
  %17 = phi i32 [ 0, %0 ], [ %19, %14 ]
  %18 = mul nsw i32 %15, %16, !dbg !49
  %19 = add nsw i32 %18, %17, !dbg !52
  tail call void @llvm.dbg.value(metadata i32 %19, i64 0, metadata !26, metadata !34), !dbg !46
  %20 = icmp eq i32 %15, 16, !dbg !53
  tail call void @llvm.dbg.value(metadata i32 0, i64 0, metadata !31, metadata !34), !dbg !44
  %21 = add i32 %15, 1, !dbg !55
  %22 = select i1 %20, i32 1, i32 %21, !dbg !55
  tail call void @llvm.dbg.value(metadata i32 %22, i64 0, metadata !31, metadata !34), !dbg !44
  %23 = zext i1 %20 to i32
  %24 = add nsw i32 %16, %23
  tail call void @llvm.dbg.value(metadata i32 %22, i64 0, metadata !31, metadata !34), !dbg !44
  tail call void @llvm.dbg.value(metadata i32 %24, i64 0, metadata !30, metadata !34), !dbg !45
  tail call void @llvm.dbg.value(metadata i32 %19, i64 0, metadata !26, metadata !34), !dbg !46
  %25 = icmp slt i32 %24, 16, !dbg !56
  br i1 %25, label %14, label %12, !dbg !47

; <label>:26:                                     ; preds = %26, %12
  %27 = phi i32 [ 0, %12 ], [ %34, %26 ]
  %28 = phi i32 [ 0, %12 ], [ %36, %26 ]
  %29 = phi i32 [ 0, %12 ], [ %31, %26 ]
  %30 = mul nsw i32 %27, %28, !dbg !49
  %31 = add nsw i32 %30, %29, !dbg !52
  tail call void @llvm.dbg.value(metadata i32 %19, i64 0, metadata !26, metadata !34), !dbg !46
  %32 = icmp eq i32 %27, 16, !dbg !53
  tail call void @llvm.dbg.value(metadata i32 0, i64 0, metadata !31, metadata !34), !dbg !44
  %33 = add i32 %27, 1, !dbg !55
  %34 = select i1 %32, i32 1, i32 %33, !dbg !55
  tail call void @llvm.dbg.value(metadata i32 %22, i64 0, metadata !31, metadata !34), !dbg !44
  %35 = zext i1 %32 to i32
  %36 = add nsw i32 %28, %35
  tail call void @llvm.dbg.value(metadata i32 %22, i64 0, metadata !31, metadata !34), !dbg !44
  tail call void @llvm.dbg.value(metadata i32 %24, i64 0, metadata !30, metadata !34), !dbg !45
  tail call void @llvm.dbg.value(metadata i32 %19, i64 0, metadata !26, metadata !34), !dbg !46
  %37 = icmp slt i32 %36, 16, !dbg !56
  br i1 %37, label %26, label %38, !dbg !47

; <label>:38:                                     ; preds = %26
  %39 = tail call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @.str.1, i32 0, i32 0), i32 %31), !dbg !48
  tail call void @llvm.dbg.value(metadata i32 1, i64 0, metadata !13, metadata !34), !dbg !35
  tail call void @llvm.dbg.value(metadata i32 1, i64 0, metadata !13, metadata !34), !dbg !35
  tail call void @llvm.dbg.value(metadata i32 0, i64 0, metadata !31, metadata !34), !dbg !44
  tail call void @llvm.dbg.value(metadata i32 0, i64 0, metadata !30, metadata !34), !dbg !45
  tail call void @llvm.dbg.value(metadata i32 0, i64 0, metadata !26, metadata !34), !dbg !46
  br label %40, !dbg !47

; <label>:40:                                     ; preds = %40, %38
  %41 = phi i32 [ 0, %38 ], [ %48, %40 ]
  %42 = phi i32 [ 0, %38 ], [ %50, %40 ]
  %43 = phi i32 [ 0, %38 ], [ %45, %40 ]
  %44 = mul nsw i32 %41, %42, !dbg !49
  %45 = add nsw i32 %44, %43, !dbg !52
  tail call void @llvm.dbg.value(metadata i32 %19, i64 0, metadata !26, metadata !34), !dbg !46
  %46 = icmp eq i32 %41, 16, !dbg !53
  tail call void @llvm.dbg.value(metadata i32 0, i64 0, metadata !31, metadata !34), !dbg !44
  %47 = add i32 %41, 1, !dbg !55
  %48 = select i1 %46, i32 1, i32 %47, !dbg !55
  tail call void @llvm.dbg.value(metadata i32 %22, i64 0, metadata !31, metadata !34), !dbg !44
  %49 = zext i1 %46 to i32
  %50 = add nsw i32 %42, %49
  tail call void @llvm.dbg.value(metadata i32 %22, i64 0, metadata !31, metadata !34), !dbg !44
  tail call void @llvm.dbg.value(metadata i32 %24, i64 0, metadata !30, metadata !34), !dbg !45
  tail call void @llvm.dbg.value(metadata i32 %19, i64 0, metadata !26, metadata !34), !dbg !46
  %51 = icmp slt i32 %50, 16, !dbg !56
  br i1 %51, label %40, label %52, !dbg !47

; <label>:52:                                     ; preds = %40
  %53 = tail call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @.str.1, i32 0, i32 0), i32 %45), !dbg !48
  tail call void @llvm.dbg.value(metadata i32 1, i64 0, metadata !13, metadata !34), !dbg !35
  tail call void @llvm.dbg.value(metadata i32 1, i64 0, metadata !13, metadata !34), !dbg !35
  %54 = tail call i32 @puts(i8* getelementptr inbounds ([37 x i8], [37 x i8]* @str.11, i32 0, i32 0)), !dbg !57
  ret i32 0, !dbg !58
}

; Function Attrs: nounwind
declare i32 @printf(i8* nocapture readonly, ...) local_unnamed_addr #1

; Function Attrs: nounwind readnone
declare void @llvm.dbg.value(metadata, i64, metadata, metadata) #2

; Function Attrs: nounwind
declare i32 @puts(i8* nocapture readonly) #3

attributes #0 = { nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="cortex-a8" "target-features"="+dsp,+neon,+vfp3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="cortex-a8" "target-features"="+dsp,+neon,+vfp3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind readnone }
attributes #3 = { nounwind }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!3, !4, !5, !6}
!llvm.ident = !{!7}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "clang version 5.0.0 (trunk 296996) (llvm/trunk 296995)", isOptimized: true, runtimeVersion: 0, emissionKind: FullDebug, enums: !2)
!1 = !DIFile(filename: "bench.c", directory: "/home/lincoln/ccf_6x6/ccf/work/benchmarks/MiBench/basicmath-CCF/benchmark")
!2 = !{}
!3 = !{i32 2, !"Dwarf Version", i32 4}
!4 = !{i32 2, !"Debug Info Version", i32 3}
!5 = !{i32 1, !"wchar_size", i32 4}
!6 = !{i32 1, !"min_enum_size", i32 4}
!7 = !{!"clang version 5.0.0 (trunk 296996) (llvm/trunk 296995)"}
!8 = distinct !DISubprogram(name: "main", scope: !1, file: !1, line: 3, type: !9, isLocal: false, isDefinition: true, scopeLine: 4, isOptimized: true, unit: !0, variables: !12)
!9 = !DISubroutineType(types: !10)
!10 = !{!11}
!11 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!12 = !{!13, !14, !18, !20, !24, !26, !30, !31}
!13 = !DILocalVariable(name: "i", scope: !8, file: !1, line: 6, type: !11)
!14 = !DILocalVariable(name: "val", scope: !15, file: !1, line: 9, type: !11)
!15 = distinct !DILexicalBlock(scope: !16, file: !1, line: 8, column: 2)
!16 = distinct !DILexicalBlock(scope: !17, file: !1, line: 7, column: 2)
!17 = distinct !DILexicalBlock(scope: !8, file: !1, line: 7, column: 2)
!18 = !DILocalVariable(name: "j", scope: !19, file: !1, line: 11, type: !11)
!19 = distinct !DILexicalBlock(scope: !15, file: !1, line: 11, column: 3)
!20 = !DILocalVariable(name: "val", scope: !21, file: !1, line: 21, type: !11)
!21 = distinct !DILexicalBlock(scope: !22, file: !1, line: 20, column: 2)
!22 = distinct !DILexicalBlock(scope: !23, file: !1, line: 19, column: 2)
!23 = distinct !DILexicalBlock(scope: !8, file: !1, line: 19, column: 2)
!24 = !DILocalVariable(name: "j", scope: !25, file: !1, line: 23, type: !11)
!25 = distinct !DILexicalBlock(scope: !21, file: !1, line: 23, column: 3)
!26 = !DILocalVariable(name: "val", scope: !27, file: !1, line: 33, type: !11)
!27 = distinct !DILexicalBlock(scope: !28, file: !1, line: 32, column: 2)
!28 = distinct !DILexicalBlock(scope: !29, file: !1, line: 31, column: 2)
!29 = distinct !DILexicalBlock(scope: !8, file: !1, line: 31, column: 2)
!30 = !DILocalVariable(name: "k", scope: !27, file: !1, line: 34, type: !11)
!31 = !DILocalVariable(name: "j", scope: !32, file: !1, line: 36, type: !11)
!32 = distinct !DILexicalBlock(scope: !27, file: !1, line: 36, column: 3)
!33 = !DILocation(line: 5, column: 2, scope: !8)
!34 = !DIExpression()
!35 = !DILocation(line: 6, column: 6, scope: !8)
!36 = !DILocation(line: 9, column: 7, scope: !15)
!37 = !DILocation(line: 15, column: 3, scope: !15)
!38 = !DILocation(line: 17, column: 2, scope: !8)
!39 = !DILocation(line: 18, column: 2, scope: !8)
!40 = !DILocation(line: 21, column: 7, scope: !21)
!41 = !DILocation(line: 27, column: 3, scope: !21)
!42 = !DILocation(line: 29, column: 2, scope: !8)
!43 = !DILocation(line: 30, column: 2, scope: !8)
!44 = !DILocation(line: 36, column: 11, scope: !32)
!45 = !DILocation(line: 34, column: 7, scope: !27)
!46 = !DILocation(line: 33, column: 7, scope: !27)
!47 = !DILocation(line: 36, column: 3, scope: !32)
!48 = !DILocation(line: 45, column: 3, scope: !27)
!49 = !DILocation(line: 38, column: 17, scope: !50)
!50 = distinct !DILexicalBlock(scope: !51, file: !1, line: 37, column: 3)
!51 = distinct !DILexicalBlock(scope: !32, file: !1, line: 36, column: 3)
!52 = !DILocation(line: 38, column: 14, scope: !50)
!53 = !DILocation(line: 39, column: 9, scope: !54)
!54 = distinct !DILexicalBlock(scope: !50, file: !1, line: 39, column: 7)
!55 = !DILocation(line: 36, column: 27, scope: !51)
!56 = !DILocation(line: 36, column: 20, scope: !51)
!57 = !DILocation(line: 47, column: 2, scope: !8)
!58 = !DILocation(line: 48, column: 2, scope: !8)
