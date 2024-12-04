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
  br label %.preheader

.preheader:                                       ; preds = %.preheader, %.preheader.preheader
  %indvars.iv = phi i64 [ 100, %.preheader.preheader ], [ %indvars.iv.next.4, %.preheader ]
  %2 = getelementptr inbounds [1000 x i32], ptr %0, i64 0, i64 %indvars.iv
  %3 = load i32, ptr %2, align 4
  %4 = add nsw i32 %3, 10
  store i32 %4, ptr %2, align 4
  %indvars.iv.next = add nuw nsw i64 %indvars.iv, 1
  %5 = getelementptr inbounds [1000 x i32], ptr %0, i64 0, i64 %indvars.iv.next
  %6 = load i32, ptr %5, align 4
  %7 = add nsw i32 %6, 10
  store i32 %7, ptr %5, align 4
  %indvars.iv.next.1 = add nuw nsw i64 %indvars.iv, 2
  %8 = getelementptr inbounds [1000 x i32], ptr %0, i64 0, i64 %indvars.iv.next.1
  %9 = load i32, ptr %8, align 4
  %10 = add nsw i32 %9, 10
  store i32 %10, ptr %8, align 4
  %indvars.iv.next.2 = add nuw nsw i64 %indvars.iv, 3
  %11 = getelementptr inbounds [1000 x i32], ptr %0, i64 0, i64 %indvars.iv.next.2
  %12 = load i32, ptr %11, align 4
  %13 = add nsw i32 %12, 10
  store i32 %13, ptr %11, align 4
  %indvars.iv.next.3 = add nuw nsw i64 %indvars.iv, 4
  %14 = getelementptr inbounds [1000 x i32], ptr %0, i64 0, i64 %indvars.iv.next.3
  %15 = load i32, ptr %14, align 4
  %16 = add nsw i32 %15, 10
  store i32 %16, ptr %14, align 4
  %indvars.iv.next.4 = add nuw nsw i64 %indvars.iv, 5
  %exitcond.not.4 = icmp eq i64 %indvars.iv.next.4, 1000
  br i1 %exitcond.not.4, label %17, label %.preheader

17:                                               ; preds = %.preheader
  %18 = tail call i32 @bar(i32 noundef 2023)
  br label %19

19:                                               ; preds = %17, %19
  %indvars.iv19 = phi i64 [ 0, %17 ], [ %indvars.iv.next20, %19 ]
  %20 = load ptr, ptr @stdout, align 8
  %21 = getelementptr inbounds [1000 x i32], ptr %0, i64 0, i64 %indvars.iv19
  %22 = load i32, ptr %21, align 4
  %23 = tail call i32 (ptr, ptr, ...) @fprintf(ptr noundef %20, ptr noundef nonnull @.str.1, i32 noundef %22)
  %indvars.iv.next20 = add nuw nsw i64 %indvars.iv19, 1
  %exitcond22.not = icmp eq i64 %indvars.iv.next20, 1000
  br i1 %exitcond22.not, label %24, label %19

24:                                               ; preds = %19
  %25 = load ptr, ptr @stdout, align 8
  %26 = tail call i64 @fwrite(ptr nonnull @.str.2, i64 5, i64 1, ptr %25)
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
