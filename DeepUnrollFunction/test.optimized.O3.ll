; ModuleID = 'test.optimized.ll'
source_filename = "test.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@stdout = external local_unnamed_addr global ptr, align 8
@.str.1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@.str.2 = private unnamed_addr constant [6 x i8] c"hello\00", align 1

; Function Attrs: nofree noinline nounwind uwtable
define dso_local noundef i32 @foo(i32 noundef %0) local_unnamed_addr #0 {
  %2 = tail call i32 (ptr, ...) @printf(ptr noundef nonnull dereferenceable(1) @.str, i32 noundef %0)
  ret i32 1
}

; Function Attrs: nofree nounwind
declare noundef i32 @printf(ptr nocapture noundef readonly, ...) local_unnamed_addr #1

; Function Attrs: nofree noinline nounwind uwtable
define dso_local noundef i32 @bar(i32 noundef %0) local_unnamed_addr #0 {
  %2 = tail call i32 (ptr, ...) @printf(ptr noundef nonnull dereferenceable(1) @.str, i32 noundef %0)
  ret i32 2
}

; Function Attrs: nofree noinline nounwind uwtable
define dso_local noundef i32 @main() local_unnamed_addr #0 {
.preheader.preheader:
  %0 = alloca [1000 x i32], align 16
  %1 = tail call i32 @foo(i32 noundef 24)
  call void @llvm.memset.p0.i64(ptr noundef nonnull align 16 dereferenceable(4000) %0, i8 0, i64 4000, i1 false)
  br label %vector.body

vector.body:                                      ; preds = %vector.body, %.preheader.preheader
  %index = phi i64 [ 0, %.preheader.preheader ], [ %index.next.1, %vector.body ]
  %offset.idx = add nuw nsw i64 %index, 100
  %2 = getelementptr inbounds [1000 x i32], ptr %0, i64 0, i64 %offset.idx
  %3 = getelementptr inbounds i32, ptr %2, i64 4
  %wide.load = load <4 x i32>, ptr %2, align 16
  %wide.load23 = load <4 x i32>, ptr %3, align 16
  %4 = add nsw <4 x i32> %wide.load, <i32 10, i32 10, i32 10, i32 10>
  %5 = add nsw <4 x i32> %wide.load23, <i32 10, i32 10, i32 10, i32 10>
  store <4 x i32> %4, ptr %2, align 16
  store <4 x i32> %5, ptr %3, align 16
  %offset.idx.1 = add nuw nsw i64 %index, 108
  %6 = getelementptr inbounds [1000 x i32], ptr %0, i64 0, i64 %offset.idx.1
  %7 = getelementptr inbounds i32, ptr %6, i64 4
  %wide.load.1 = load <4 x i32>, ptr %6, align 16
  %wide.load23.1 = load <4 x i32>, ptr %7, align 16
  %8 = add nsw <4 x i32> %wide.load.1, <i32 10, i32 10, i32 10, i32 10>
  %9 = add nsw <4 x i32> %wide.load23.1, <i32 10, i32 10, i32 10, i32 10>
  store <4 x i32> %8, ptr %6, align 16
  store <4 x i32> %9, ptr %7, align 16
  %index.next.1 = add nuw nsw i64 %index, 16
  %10 = icmp eq i64 %index.next.1, 896
  br i1 %10, label %.preheader, label %vector.body, !llvm.loop !6

.preheader:                                       ; preds = %vector.body
  %11 = getelementptr inbounds [1000 x i32], ptr %0, i64 0, i64 996
  %12 = load i32, ptr %11, align 16
  %13 = add nsw i32 %12, 10
  store i32 %13, ptr %11, align 16
  %14 = getelementptr inbounds [1000 x i32], ptr %0, i64 0, i64 997
  %15 = load i32, ptr %14, align 4
  %16 = add nsw i32 %15, 10
  store i32 %16, ptr %14, align 4
  %17 = getelementptr inbounds [1000 x i32], ptr %0, i64 0, i64 998
  %18 = load i32, ptr %17, align 8
  %19 = add nsw i32 %18, 10
  store i32 %19, ptr %17, align 8
  %20 = getelementptr inbounds [1000 x i32], ptr %0, i64 0, i64 999
  %21 = load i32, ptr %20, align 4
  %22 = add nsw i32 %21, 10
  store i32 %22, ptr %20, align 4
  %23 = tail call i32 @bar(i32 noundef 2023)
  br label %24

24:                                               ; preds = %.preheader, %24
  %indvars.iv19 = phi i64 [ 0, %.preheader ], [ %indvars.iv.next20, %24 ]
  %25 = load ptr, ptr @stdout, align 8
  %26 = getelementptr inbounds [1000 x i32], ptr %0, i64 0, i64 %indvars.iv19
  %27 = load i32, ptr %26, align 4
  %28 = tail call i32 (ptr, ptr, ...) @fprintf(ptr noundef %25, ptr noundef nonnull @.str.1, i32 noundef %27)
  %indvars.iv.next20 = add nuw nsw i64 %indvars.iv19, 1
  %exitcond22.not = icmp eq i64 %indvars.iv.next20, 1000
  br i1 %exitcond22.not, label %29, label %24

29:                                               ; preds = %24
  %30 = load ptr, ptr @stdout, align 8
  %31 = tail call i64 @fwrite(ptr nonnull @.str.2, i64 5, i64 1, ptr %30)
  ret i32 0
}

; Function Attrs: nofree nounwind
declare noundef i32 @fprintf(ptr nocapture noundef, ptr nocapture noundef readonly, ...) local_unnamed_addr #1

; Function Attrs: nofree nounwind
declare noundef i64 @fwrite(ptr nocapture noundef, i64 noundef, i64 noundef, ptr nocapture noundef) local_unnamed_addr #2

; Function Attrs: nocallback nofree nounwind willreturn memory(argmem: write)
declare void @llvm.memset.p0.i64(ptr nocapture writeonly, i8, i64, i1 immarg) #3

attributes #0 = { nofree noinline nounwind uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nofree nounwind "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { nofree nounwind }
attributes #3 = { nocallback nofree nounwind willreturn memory(argmem: write) }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"clang version 18.1.8 (https://github.com/llvm/llvm-project.git 3b5b5c1ec4a3095ab096dd780e84d7ab81f3d7ff)"}
!6 = distinct !{!6, !7, !8}
!7 = !{!"llvm.loop.isvectorized", i32 1}
!8 = !{!"llvm.loop.unroll.runtime.disable"}
